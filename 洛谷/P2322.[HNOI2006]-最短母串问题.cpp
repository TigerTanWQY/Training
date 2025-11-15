#include <bits/stdc++.h>
using namespace std;
constexpr const int N = 603;
int fail[N], trie[N][26], state[N], ans[6000003], fa[6000003];
bool vis[N][10003];
int tot=0;
int n, maxn;
char s[N];
void make_trie(char s[], int Num) {
	int now=0, len=strlen(s);
	for(int i=0; i<len; i++) {
		int nxt=s[i]-'A';
		if(!trie[now][nxt]) {
			trie[now][nxt]=++tot;
		}
		now=trie[now][nxt];
	}
	state[now]|=(1<<(Num-1));
}
void getfail() {
	queue<int> q;
	for(int i=0; i<26; i++) {
		if(trie[0][i]) {
			fail[trie[0][i]]=0;
			q.push(trie[0][i]);
		}
	}
	int now=0;
	while(!q.empty()) {
		now=q.front();
		q.pop();
		for(int i=0; i<26; i++) {
			if(trie[now][i]) {
				fail[trie[now][i]]=trie[fail[now]][i];
				state[trie[now][i]]|=state[trie[fail[now]][i]];
				q.push(trie[now][i]);
			} else {
				trie[now][i]=trie[fail[now]][i];
			}
		}
	}
}
void bfs() {
	char s[2003];
	queue<int> q1, q2;
	q1.push(0), q2.push(0);
	int t=0, cnt=0, qaq=0;
	while(!q1.empty()) {
		int now=q1.front(), st=q2.front();
		q1.pop(), q2.pop();
		if(st==(1<<n)-1) {
			while(t) {
				s[++cnt]=ans[t];
				t=fa[t];
			}
			for(int i=cnt; i>=1; i--)
				cout.put(s[i]+'A');
			cout << endl; exit(0); return;
		}
		for(int i=0; i<26; i++) {
			if(!vis[trie[now][i]][st|state[trie[now][i]]]) {
				vis[trie[now][i]][st|state[trie[now][i]]]=1;
				fa[++qaq]=t;
				ans[qaq]=i;
				q1.push(trie[now][i]);
				q2.push(st|state[trie[now][i]]);
			}
		}
		++t;
	}
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> s;
		make_trie(s, i);
	}
	getfail();
	bfs();
	return 0;
}
