#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int N = 2003;
priority_queue<pair<int, int>> q;
vector<int> G[2][N];
int d[N], n;

void Dijkstra(const int& v) {
	memset(d, 0, sizeof(d));
	q.push({0, v});
	while(!q.empty()) {
		int u = q.top().second;
		if(d[u] > -q.top().first || d[u] == 0) {
			d[u] = -q.top().first;
			for(int i = 0; i < G[0][u].size(); ++i)
				if(d[u] + G[0][u][i] < d[G[1][u][i]] || d[G[1][u][i]] == 0)
					q.push({-d[u] - G[0][u][i], G[1][u][i]});
		}
		q.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[0][u].push_back(w);
		G[1][u].push_back(v);
	}
	for(int v = 1; v <= n; ++v) {
		Dijkstra(v);
		if(d[v] == 0)
			cout << "-1";
		else
			cout << d[v];
		cout << '\n';
	}
	return 0;
}