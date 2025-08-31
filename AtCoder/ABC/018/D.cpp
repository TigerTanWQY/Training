#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 21;
bitset<N> vis;
int G[N][N], s[N], H, W, n, m, ans = 0;

void dfs(int u, int cnt) {
	if(cnt > n)
		return;
	else if(u > H) {
		if(cnt == n) {
			int res = 0;
			memset(s, 0, sizeof(s));
			for(int i = 1; i <= W; ++i)
				for(int j = 1; j <= H; ++j)
					if(vis[j])
						s[i] += G[j][i];
			sort(s + 1, s + W + 1, greater<int>());
			for(int i = 1; i <= m; ++i)
				res += s[i];
			ans = max(ans, res);
		}
		return;
	}
	vis[u] = true;
	dfs(u + 1, cnt + 1);
	vis[u] = false;
	dfs(u + 1, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k;
	cin >> H >> W >> n >> m >> k;
	for(int u, v, w; k--; ) {
		cin >> u >> v >> w;
		G[u][v] += w;
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
