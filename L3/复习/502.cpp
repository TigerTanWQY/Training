#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 1e3 + 3;
vector<pair<int, int>> G[N];
int dis[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	for(int u = 1; u <= n; ++u)
		for(const auto& [v, w]: G[u])
			dis[v] = min(dis[v], dis[u] + w);
	cout << dis[n] << endl;
	return 0;
}