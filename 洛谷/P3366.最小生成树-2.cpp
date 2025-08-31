#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

constexpr const int N = 5003;
vector<pair<int, int>> G[N];
bitset<N> vis;
int dis[N], n;

int Prim(const int rt) {
	memset(dis, 0x3f, sizeof(dis));
	dis[rt] = 0;
	__gnu_pbds::priority_queue<pair<int, int>, greater<>> q;
	q.push({dis[rt], rt});
	vis.reset();
	int res = 0;
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		res += dis[u];
		for(const auto& [v, w]: G[u])
			if(!vis[v] && dis[v] > w) {
				dis[v] = w;
				q.push({dis[v], v});
			}
	}
	if(vis.count() != n)
		res = 0x3f3f3f3f;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	int ans = Prim(1);
	if(ans == 0x3f3f3f3f)
		cout << "orz";
	else
		cout << ans;
	cout << endl;
	return 0;
}
