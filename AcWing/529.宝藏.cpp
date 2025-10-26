#include <bits/stdc++.h>
using namespace std;

constexpr const int INF = 0x3f3f3f3f, N = 15;
int G[N][N], nxt[1<<N], f[1<<N][1003], n;

int calc(int S, int T) {
	if((nxt[T] & S) != S)
		return -1;
	int R = T ^ S, cnt = 0;
	for(int i = 0; i < n; ++ i)
		if(R >> i & 1) {
			int t = INF;
			for(int j = 0; j < n; ++j)
				if(T >> j & 1)
					t = min(t, G[j][i]);
			cnt += t;
		}
	return cnt;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m; cin >> n >> m;
	memset(G, 0x3f, sizeof G);
	for(int i = 0; i < n; ++i)
		G[i][i] = 0;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		--u; --v;
		G[u][v] = G[v][u] = min(G[u][v], w);
	}
	for(int S = 1; S < 1<<n; ++S)
		for(int i = 0; i < n; ++i)
			if(S >> i & 1)
				for(int j = 0; j < n; ++j)
					if(G[i][j] != INF)
						nxt[S] |= 1 << j;
	memset(f, 0x3f, sizeof f);
	for(int i = 0; i < n; ++i)
		f[1<<i][0] = 0;
	for(int S = 1, cnt; S < 1<<n; ++S)
		for(int T = S-1 & S; T; T = T-1 & S)
			if(~(cnt = calc(S, T)))
				for(int k = 1; k < n; ++k)
					f[S][k] = min(f[S][k], f[T][k - 1] + cnt * k);
	int res = INF;
	for(int k = 0; k < n; ++k)
		res = min(res, f[(1<<n) - 1][k]);
	cout << res << endl;
	return 0;
}
