#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 21;
int G[N][N], tot[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int H, W, n, m, k;
	cin >> H >> W >> n >> m >> k;
	for(int u, v, w; k--; ) {
		cin >> u >> v >> w;
		--u; --v;
		G[u][v] += w;
	}
	int ans = 0;
	for(unsigned s = 0; s < 1U << H; ++s) {
		if(popcount(s) != n)
			continue;
		int res = 0;
		memset(tot, 0, sizeof(tot));
		for(int i = 0; i < W; ++i)
			for(int j = 0; j < H; ++j)
				if(s >> j & 1)
					tot[i] += G[j][i];
		sort(tot, tot + W, greater<int>());
		for(int i = 0; i < m; ++i)
			res += tot[i];
		ans = max(ans, res);
	}
	cout << ans << endl;
	return 0;
}
