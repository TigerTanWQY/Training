#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 303;
int f[12][N][N], G[2][N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; ++i)
		f[0][i][i] = 0;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		f[0][u][v] = w;
	}
	for(int k = 1; k <= 9; ++k)
		for(int u = 1; u <= n; ++u)
			for(int v = 1; v <= n; ++v)
				for(int t = 1; t <= n; ++t)
					if(f[k - 1][u][t] < INF && f[k - 1][t][v] < INF)
						f[k][u][v] = min(f[k][u][v], f[k - 1][u][t] + f[k - 1][t][v]);
	memset(G[0], 0x3f, sizeof(G[0]));
	for(int i = 1; i <= n; ++i)
		G[0][i][i] = 0;
	int ans = 0;
	for(int k = 9; k >= 0; --k) {
		memset(G[1], 0x3f, sizeof(G[1]));
		for(int u = 1; u <= n; ++u)
			for(int v = 1; v <= n; ++v)
				for(int t = 1; t <= n; ++t)
					if(G[0][u][t] < INF && f[k][t][v] < INF)
						G[1][u][v] = min(G[1][u][v], G[0][u][t] + f[k][t][v]);
		bool flag = true;
		for(int u = 1; flag && u <= n; ++u)
			if(G[1][u][u] < 0)
				flag = false;
		if(flag) {
			ans += (1 << k);
			memcpy(G[0], G[1], sizeof(G[0]));
		}
	}
	++ans;
	if(ans > n)
		ans = -1;
	cout << ans;
	cout << endl;
	return 0;
}