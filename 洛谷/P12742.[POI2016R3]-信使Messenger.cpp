#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 103, V = 53;
bool G[N][N];
int f[N][N][V], g[N][N][V], h[N][N][V];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, p, _q;
	cin >> n >> m >> p;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u][v] = true;
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(G[i][j])
				f[i][j][1] = h[i][j][1] = 1;
	for(int k = 2; k <= 50; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				for(int l = 1; l <= n; ++l)
					if(G[l][j])
						f[i][j][k] = (f[i][j][k] + f[i][l][k-1]) % p;
	for(int k = 2; k <= 50; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j) {
				if(i == j)
					continue;
				long long x = 0, y = 0;
				for(int d = 1; d < k; ++d) {
					x = (x + 1LL * g[i][j][d] * f[i][j][k-d] % p) % p;
					x = (x + 1LL * h[i][j][d] * f[j][j][k-d] % p) % p;
					y = (y + 1LL * g[i][j][d] * f[i][i][k-d] % p) % p;
					y = (y + 1LL * h[i][j][d] * f[j][i][k-d] % p) % p;
				}
				h[i][j][k] = (f[i][j][k] - x + p) % p;
				g[i][j][k] = (f[i][i][k] - y  +p) % p;
			}
	cin >> _q;
	for(int u, v, d; _q--; cout.put('\n')){
		cin >> u >> v >> d;
		cout << h[u][v][d];
	}
	cout.flush(); return 0;
}
