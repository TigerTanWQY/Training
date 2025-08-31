#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int N = 500003;
const int M = 26;
struct Node
{ int nxt[M], go[M], fail = 0, cnte = 0; }
AC[N];
vector<int> bfn;
int idx[N], cnt = 0;

void ist(const string& s, const int& x) {
	int now = 0;
	for(const auto& ch: s) {
		if(!AC[now].nxt[ch - 'a'])
			AC[now].nxt[ch - 'a'] = ++cnt;
		now = AC[now].nxt[ch - 'a'];
	}
	idx[x] = now;
}

void build() {
	queue<int> q;
	q.push(0);
	bfn.push_back(0);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < M; ++i)
			if(AC[u].nxt[i]) {
				q.push(AC[u].nxt[i]);
				bfn.push_back(AC[u].nxt[i]);
				AC[u].go[i] = AC[u].nxt[i];
				if(u == 0)
					AC[AC[u].nxt[i]].fail = 0;
				else
					AC[AC[u].nxt[i]].fail = AC[AC[u].fail].go[i];
			} else
				if(u == 0)
					AC[u].go[i] = 0;
				else
					AC[u].go[i] = AC[AC[u].fail].go[i];
	}
}

void AC_query(const string& s) {
	int now = 0;
	for(const auto& ch: s) {
		if(ch == '\0')
			now = 0;
		else
			now = AC[now].go[ch - 'a'];
		++AC[now].cnte;
	}
	for(auto cit = bfn.crbegin(); cit != bfn.crend(); ++cit)
		AC[AC[*cit].fail].cnte += AC[*cit].cnte;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int n;
	cin >> n;
	string t;
	for(int i = 1; i <= n; ++i) {
		cin >> t;
		ist(t, i);
	}
	build();
	AC_query(s);
	for(int i = 1; i <= n; ++i)
		cout << AC[idx[i]].cnte << '\n';
	cout.flush();
	return 0;
}