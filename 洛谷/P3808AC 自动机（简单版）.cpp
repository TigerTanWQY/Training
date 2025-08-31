#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int N = 1000003;
struct Tree {
	int nxt[29];
	int fail, cnte;
} AC[N];
int cnt = 0;

void build(const string& s) {
	int now = 0;
	for(const auto& ch: s) {
		if(AC[now].nxt[ch - 'a'] == 0)
			AC[now].nxt[ch - 'a'] = ++cnt;
		now = AC[now].nxt[ch - 'a'];
	}
	++AC[now].cnte;
}

void get_fail() {
	queue<int> q;
	for(int i = 0; i < 26; ++i)
		if(AC[0].nxt[i]) {
			AC[AC[0].nxt[i]].fail = 0;
			q.push(AC[0].nxt[i]);
		}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < 26; ++i)
			if(AC[u].nxt[i]) {
				AC[AC[u].nxt[i]].fail = AC[AC[u].fail].nxt[i];
				q.push(AC[u].nxt[i]);
			} else
				AC[u].nxt[i] = AC[AC[u].fail].nxt[i];
	}
}

int AC_query(const string& s) {
	int len = s.size(), now = 0, res = 0;
	for(int i = 0; i < len; ++i) {
		now = AC[now].nxt[s[i] - 'a'];
		for(int t = now; t && AC[t].cnte != -1; t = AC[t].fail) {
			res += AC[t].cnte;
			AC[t].cnte = -1;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(string s; n--; ) {
		cin >> s;
		build(s);
	}
	AC[0].fail = 0;
	get_fail();
	string t;
	cin >> t;
	cout << AC_query(t);
	cout << endl;
	return 0;
}