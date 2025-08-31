#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
using namespace std;
#define mkp make_pair

const int N = 100003;
vector<int> G[N];
bitset<N> vis;
int a[N], d[2][N], dis[N], n;

void Dijkstra() {
	memset(dis, 0x3f, sizeof(dis));
	vis.reset();
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	for(int i = 1; i <= n; ++i)
		if(!d[0][i]) {
			dis[i] = a[i];
			q.push(mkp(dis[i], i));
		}
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i];
			if(dis[v] > dis[u] + a[v]) {
				dis[v] = dis[u] + a[v];
				q.push(mkp(dis[v], v));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int m; cin >> n >> m; cout.put('\n')) {
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		for(int u, v; m--; ) {
			cin >> u >> v;
			G[u].push_back(v);
			++d[0][v]; ++d[1][u];
		}
		Dijkstra();
		int ans = -2e9;
		for(int i = 1; i <= n; ++i)
			if(!d[1][i])
				ans = max(ans, dis[i]);
		cout << ans;
		for(int i = 1; i <= n; ++i) {
			G[i].clear();
			d[0][i] = d[1][i] = 0;
		}
	}
	cout.flush();
	return 0;
}