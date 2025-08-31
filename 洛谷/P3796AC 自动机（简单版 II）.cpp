#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1000003;
struct Tree
{ int nxt[29], fail, cnte; }
AC[N];
struct Res {
	int val, pos;
	bool operator<(const Res& x) const {
		if(val != x.val)
			return val > x.val;
		else
			return pos < x.pos;
	}
} ans[N];
string a[N];
int cnt;

void clean(const int& x) {
	memset(AC[x].nxt, 0, sizeof(AC[x].nxt));
	AC[x].fail = AC[x].cnte = 0;
}

void build(const string& s, const int& val) {
	int now = 0;
	for(const auto& ch: s) {
		if(AC[now].nxt[ch - 'a'] == 0) {
			AC[now].nxt[ch - 'a'] = ++cnt;
			clean(cnt);
		}
		now = AC[now].nxt[ch - 'a'];
	}
	AC[now].cnte = val;
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
	int now = 0, res = 0;
	for(const auto& ch: s) {
		now = AC[now].nxt[ch - 'a'];
		for(int t = now; t; t = AC[t].fail)
			++ans[AC[t].cnte].val;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int n; ; ) {
		cin >> n;
		if(!n)
			break;
		cnt = 0;
		clean(0);
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			ans[i].val = 0;
			ans[i].pos = i;
			build(a[i], i);
		}
		AC[0].fail = 0;
		get_fail();
		cin >> a[0];
		AC_query(a[0]);
		sort(ans + 1, ans + n + 1);
		cout << ans[1].val << '\n' << a[ans[1].pos] << '\n';
		for(int i = 2; i <= n; ++i)
			if(ans[i].val == ans[i - 1].val)
				cout << a[ans[i].pos] << '\n';
			else
				break;
	}
	cout.flush();
	return 0;
}