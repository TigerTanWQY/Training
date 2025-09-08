#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, X;
	cin >> n >> m >> X;
	vector<vector<int>> adj[2];
	adj[0].resize(n + 1);
	adj[1].resize(n + 1);
	for(int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		adj[0][u].push_back(v);
		adj[1][v].push_back(u);
	}
	vector<vector<LL>> dist(2, vector<LL>(n + 1, 1e18));
	using T = tuple<LL, int, int>;
	priority_queue<T, vector<T>, greater<>> q;
	dist[0][1] = 0;
	q.push({0, 1, 0});
	while(!q.empty()) {
		auto [d, u, s] = q.top();
		q.pop();
		if(d > dist[s][u])
			continue;
		for(const auto& v: adj[s][u]) {
			LL new_d = d + 1;
			if(new_d < dist[s][v]) {
				dist[s][v] = new_d;
				q.push({new_d, v, s});
			}
		}
		int new_s = 1 - s;
		LL new_d = d + X;
		if(new_d < dist[new_s][u]) {
			dist[new_s][u] = new_d;
			q.push({new_d, u, new_s});
		}
	}
	cout << min(dist[0][n], dist[1][n]) << '\n';
	cout.flush();
	return 0;
}
