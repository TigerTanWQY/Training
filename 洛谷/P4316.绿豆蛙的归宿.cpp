#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<pair<int, int>> G[N];
int in[N], d[N], n;
double f[N];

inline void tpSort() {
	queue<int> q;
	q.push(n);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& [v, w]: G[u]) {
			f[v] += (f[u] + w) / d[v];
			if(!--in[v])
				q.push(v);
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
		G[v].push_back({u, w});
		++in[u]; ++d[u];
	}
	tpSort();
	cout << fixed << setprecision(2) << f[1] << endl;
	return 0;
}
