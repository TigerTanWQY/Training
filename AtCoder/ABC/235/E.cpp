#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int N = 200003;
vector<pair<int, int>> G[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for(int u, v, w; q--; ) {
		cin >> u >> v >> w;
	}
	return 0;
}