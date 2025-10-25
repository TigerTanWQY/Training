#include <bits/stdc++.h>
using namespace std;

int f[103][103];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, V, M;
	cin >> n >> V >> M;
	for(int v, m, w; n--; ) {
		cin >> v >> m >> w;
		for(int j = V; j >= v; --j)
			for(int k = M; k >= m; --k)
				f[j][k] = max(f[j][k], f[j-v][k-m] + w);
	}
	cout << f[V][M] << endl;
	return 0;
}
