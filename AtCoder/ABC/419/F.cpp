#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e6 + 3, P = 998244353;
unsigned g[N];
int f[103][103][259], nxt[N][27], fail[N], cnt = 0;

void add(int &x, int y) {
	x += y;
	if(x >= P)
		x -= P;
}

void ist(const string& s, int i) {
	int now = 0;
	for(const auto& ch: s) {
		if(!nxt[now][ch - 'a'])
			nxt[now][ch - 'a'] = ++cnt;
		now = nxt[now][ch - 'a'];
	}
	g[now] |= 1U << i;
}

void build() {
	queue<int> q;
	for(int i = 0; i < 26; ++i)
		if(nxt[0][i])
			q.push(nxt[0][i]);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		g[x] |= g[fail[x]];
		for(int i = 0; i < 26; ++i)
			if(!nxt[x][i])
				nxt[x][i] = nxt[fail[x]][i];
			else {
				fail[nxt[x][i]] = nxt[fail[x]][i];
				q.push(nxt[x][i]);
			}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		ist(s, i);
	}
	build();
	f[0][0][0] = 1;
	for(int i = 0; i < m; ++i)
		for(int j = 0; j <= cnt; ++j)
			for(unsigned k = 0; k < 1U << n; ++k) {
				int y = f[i][j][k];
				if(!y)
					continue;
				for(int x = 0; x < 26; ++x)
					add(f[i + 1][nxt[j][x]][k | g[nxt[j][x]]], y);
			}
	int ans = 0;
	for(int i = 0; i <= cnt; ++i)
		add(ans, f[m][i][(1U << n) - 1]);
	cout << ans << endl;
	return 0;
}
