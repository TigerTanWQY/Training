#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 8 + 3;
bool G[2][N][N];
int a[N][N], p[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[0][u][v] = G[0][v][u] = true;
	}
	cin >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[1][u][v] = G[1][v][u] = true;
	}
	for(int u = 1; u < n; ++u)
		for(int v = u + 1; v <= n; ++v) {
			cin >> a[u][v];
			a[v][u] = a[u][v];
		}
	for(int i = 1; i <= n; ++i)
		p[i] = i;
	int ans = 28'000'000;
	do {
		int res = 0;
		for(int u = 1; u <= n; ++u)
			for(int v = 1; v < u; ++v)
				if(G[1][u][v] != G[0][p[u]][p[v]])
					res += a[u][v];
		ans = min(ans, res);
	} while(next_permutation(p + 1, p + n + 1));
	cout << ans << endl;
	return 0;
}