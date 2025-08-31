#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N];
int id[N], cd[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, _q;
	cin >> n >> m >> _q;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[v].push_back(u);
		++id[u];
	}
	for(int s, t; _q--; ) {
		cin >> s >> t;
		queue<int> q;
		for(int i = 1; i <= n; ++i) {
			cd[i] = id[i];
			if(!cd[i] || i == t)
			{ f[i] = -1; q.push(i); }
			else
				f[i] = 0;
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(const auto& v: G[u]) {
				if(f[v])
					continue;
				--cd[v];
				if(!~f[u]) {
					f[v] = 1;
					q.push(v);
				} else if(!cd[v]) {
					f[v] = -1;
					q.push(v);
				}
			}
		}
		cout << f[s] << '\n';
	}
	cout.flush();
	return 0;
}
