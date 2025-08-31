#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 103;
bool b[N][N];
int f[N][N];

int main() {
	int n, m;
	cin >> n >> m;
	memset(f, 0x3f, sizeof(f));
	for(int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		f[u][v] = f[v][u] = w;
		b[u][v] = b[v][u] = true;
	}
	int ans = 0;
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(f[i][j] > f[i][k] + f[k][j]) {
					if(b[i][j]) {
						++ans;
						b[i][j] = false;
					}
					f[i][j] = f[i][k] + f[k][j];
				}
	cout << ans / 2 << endl;
	return 0;
}
