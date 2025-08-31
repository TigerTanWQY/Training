#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5003;
bitset<N> vis;
int G[N][N], dis[N], n;

int Prim(const int rt) {
	memset(dis, 0x3f, sizeof(dis));
	dis[rt] = 0;
	vis.reset();
	int res = 0;
	for(int _ = n; _--; ) {
		int u = -1;
		for(int j = 1; j <= n; ++j)
			if(!vis[j] && (u == -1 || dis[j] < dis[u]))
				u = j;
		if(dis[u] == 0x3f3f3f3f)
			return 0x3f3f3f3f;
		vis[u] = true;
		res += dis[u];
		for(int v = 1; v <= n; ++v)
			if(!vis[v] && dis[v] > G[u][v])
				dis[v] = G[u][v];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m;
	memset(G, 0x3f, sizeof(G));
	for(int i = 0; i < N; ++i)
		G[i][i] = 0;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u][v] = G[v][u] = min(G[u][v], w);
	}
	int ans = Prim(1);
	if(ans == 0x3f3f3f3f)
		cout << "orz";
	else
		cout << ans;
	cout << endl;
	return 0;
}
