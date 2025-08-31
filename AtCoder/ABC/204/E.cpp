#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#include <ext/pb_ds/priority_queue.hpp>

constexpr const int N = 1e5 + 3;
vector<tuple<int, int, int>> G[N];
bitset<N> vis;
LL dis[N];

void Dijkstra(const int rt) {
	memset(dis, 0x3f, sizeof(dis));
	dis[rt] = 0;
	__gnu_pbds::priority_queue<pair<LL, int>, greater<>> q;
	q.push({dis[rt], rt});
	vis.reset();
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(const auto& [v, w1, w2]: G[u]) {
			LL L = 0, R = w2;
			auto calc = [&w2](const double& x)
			{ return x + (w2 / (x + 1)); };
			while(L + 2 < R) {
				double M1 = L + (R - L + 1) / 3.0, M2 = R - (R - L + 1) / 3.0;
				if(calc(M1) > calc(M2))
					L = M1;
				else
					R = M2;
			}
			LL w = 0x3f3f3f3f3f3f3f3f, t = 0;
			for(int i = L; i <= R; ++i)
				if(calc(i) < w) {
					w = calc(i);
					t = i;
				}
			t = max(t, dis[u]);
			w = w1 + calc(t);
			if(dis[v] > w) {
				dis[v] = w;
				q.push({dis[v], v});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int u, v, w1, w2; m--; ) {
		cin >> u >> v >> w1 >> w2;
		G[u].push_back({v, w1, w2});
		G[v].push_back({u, w1, w2});
	}
	Dijkstra(1);
	if(dis[n] == 0x3f3f3f3f3f3f3f3f)
		cout << "-1";
	else
		cout << dis[n];
	cout << endl;
	return 0;
}
