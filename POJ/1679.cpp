#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

const int N = 103;
bitset<N> vis;
int G[N][N], dis[N], n;

inline void init () {
	memset(G, 0x3f, sizeof(G));
	for(int i = 1; i <= n; ++i)
		G[i][i] = 0;
	vis.reset();
}

int Prim() {
	int res = 0;
	for(int i = 1; i <= n; ++i)
		dis[i] = G[1][i];
	vis[1] = true;
	for(int i = 1; i < n; ++i) {
		int id = 0, w = 0x3f3f3f3f;
		for(int j = 1; j <= n; ++j)
			if(!vis[j] && dis[j] < w) {
				w = dis[j];
				id = j;
			}
		res += w;
		vis[id] = true;
		for(int j = 1; j <= n; ++j)
			if(!vis[j] && dis[j] == w)
				return -1;
		for(int j = 1; j <= n; ++j)
			 if(!vis[j])
				 if(dis[j] > G[id][j])
					 dis[j] = G[id][j];
				 else if(dis[j] == G[id][j] && dis[j] != 0x3f3f3f3f)
					 return -1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int _T;
	cin >> _T;
	for(int m; _T--; cout.put('\n')) {
		cin >> n >> m;
		init();
		for (int u, v, w; m--; ) {
			cin >> u >> v >> w;
			G[u][v] = G[v][u] = w;
		}
		const int ans = Prim();
		if(!~ans)
			cout << "Not Unique!";
		else
			cout << ans;
	}
	cout.flush();
	return 0;
}