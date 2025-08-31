#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 1e9 + 7, N = 1e5 + 3;
int nxt[N * 30][3], w[N * 30], cnt[N * 30], idx = 1;
LL ans = 0, tot = 1, ans2, tot2;

void ist(int x) {
	int now = 1;
	for(int j = 29; ~j; --j) {
		int y = x >> j & 1;
		if(!nxt[now][y]) {
			nxt[now][y] = ++idx;
			w[idx] = y << j;
		}
		now = nxt[now][y];
	}
	++cnt[now];
}

LL qpow(LL a, LL b) {
	LL res = 1;
	for(; b; a *= a, a %= P, b >>= 1)
		if(b & 1)
		{ res *= a; res %= P; }
	return res;
}

void mrge(int u, int v, int now) {
	now ^= w[u] ^ w[v];
	if(cnt[u] && cnt[v]) {
		if(now < ans2)
		{ ans2 = now; tot2 = 0; }
		if(now == ans2)
		{ tot2 += (LL)cnt[u] * cnt[v] % P; tot2 %= P; }
		return;
	}
	bool flag = false;
	if(nxt[u][0] && nxt[v][0])
	{ mrge(nxt[u][0], nxt[v][0], now); flag = true; }
	if(nxt[u][1] && nxt[v][1])
	{ mrge(nxt[u][1], nxt[v][1], now); flag = true; }
	if(flag)
		return;
	if(nxt[u][0] && nxt[v][1])
		mrge(nxt[u][0], nxt[v][1], now);
	if(nxt[u][1] && nxt[v][0])
		mrge(nxt[u][1], nxt[v][0], now);
}

bool solve(int u) {
	if(u == 0)
		return false;
	else if(cnt[u]) {
		if(cnt[u] > 2)
		{ tot *= qpow(cnt[u], cnt[u] - 2); tot %= P; }
		return true;
	}
	if(solve(nxt[u][1]) & solve(nxt[u][0])) {
		ans2 = (1LL << 30) - 1; tot2 = 1;
		mrge(nxt[u][0], nxt[u][1], 0);
		ans += ans2; tot *= tot2; tot %= P;
	}
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		ist(x);
	}
	solve(1);
	cout << ans << '\n' << tot << endl;
	return 0;
}
