#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

constexpr const int N = 2e5 + 3;
struct Node {
	int u; bool k; long long d;
	bool operator<(const Node& A) const
	{ return d > A.d; }
};
vector<pair<int, int>> G[N];
bool vis[N][3];
int in[N];
long long f[N][3];

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, rt;
	cin >> n >> m >> rt;
	for(int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		G[v].push_back({u, w});
		++in[u];
	}
	__gnu_pbds::priority_queue<Node> q;
	for(int i = 1; i <= n; ++i)
		if(in[i] == 0)
		{ q.push({i, 0, 0}); q.push({i, 1, 0}); }
		else
			f[i][0] = 1e18;
	while(!q.empty()) {
		auto [u, k, d] = q.top(); q.pop();
		if(vis[u][k])
			continue;
		vis[u][k] = 1;
		for(const auto& [v, w]: G[u])
			if(!k) {
				f[v][1] = max(f[v][1], f[u][0] + w);
				if(!--in[v])
					q.push({v, 1, f[v][1]});
			} else if(f[v][0] > f[u][1] + w) {
				f[v][0] = f[u][1] + w;
				if(!vis[v][0])
					q.push({v, 0, f[v][0]});
			}
	}
	if(f[rt][0] == 1e18)
		cout << "INFINITY";
	else
		cout << f[rt][0];
	cout << endl; return 0;
}
