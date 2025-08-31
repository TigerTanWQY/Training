#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
#include <list>
#include <algorithm>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<pair<int, int>> G[N];
bitset<N> vis;
int n;
long long dis[N];

void SPFA(int rt) {
	vis.reset();
	memset(dis, 0x3f, sizeof(dis));
	dis[rt] = 0;
	list<int> q;
	q.push_back(rt);
	vis[rt] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop_front();
		vis[u] = false;
		if(dis[q.front()] > dis[q.back()])
			swap(q.front(), q.back());
		for(const auto& [v, w]: G[u])
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if(!vis[v]) {
					q.push_back(v);
					vis[v] = true;
					if(dis[q.front()] > dis[q.back()])
						swap(q.front(), q.back());
				}
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, -w});
	}
	for(int i = 1; i <= n; ++i)
		G[0].push_back({i, 0});
	SPFA(0);
	for(int i = 1; i <= n; ++i)
		cout << dis[i] << ' ';
	cout << endl;
	return 0;
}