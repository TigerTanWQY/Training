#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 403;
vector<int> sp;
pair<int, int> E[N * N], mp[N];
int G[N][N], dis[N], ans[N * N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	memset(G, -1, sizeof(G));
	for(int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		--u; --v;
		G[u][v] = i;
		E[i] = {u, v};
	}
	memset(dis, -1, sizeof(dis));
	dis[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int v = 0; v < n; ++v)
			if(!~dis[v] && ~G[u][v]) {
				dis[v] = dis[u] + 1;
				mp[v] = {u, G[u][v]};
				q.push(v);
			}
	}
	if(!~dis[n - 1]) {
		for(int i = 0; i < m; ++i)
			cout << "-1\n";
		cout.flush(); return 0;
	}
	for(int tmp = n - 1; tmp; tmp = mp[tmp].first)
		sp.push_back(mp[tmp].second);
	for(int i = 0; i < m; ++i)
		ans[i] = dis[n - 1];
	for(const int &i: sp) {
		G[E[i].first][E[i].second] = -1;
		q.push(0);
		memset(dis, -1, sizeof(dis));
		dis[0] = 0;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int v = 0; v < n; ++v)
				if(!~dis[v] && ~G[u][v]) {
					dis[v] = dis[u] + 1;
					q.push(v);
				}
		}
		ans[i] = dis[n - 1];
		G[E[i].first][E[i].second] = i;
	}
	for(int i = 0; i < m; ++i)
		cout << ans[i] << '\n';
	cout.flush(); return 0;
}
