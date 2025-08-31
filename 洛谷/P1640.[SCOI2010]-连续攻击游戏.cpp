#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e6 + 3;
vector<int> G[N];
bitset<N> vis, b;

bool bfs(int p) {
	if(!vis[p]) {
		queue<int> q;
		q.push(p);
		vis[p] = true;
		int maxp = p, cntv = 0, cnte = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			maxp = max(maxp, u); ++cntv;
			for(const auto& v: G[u]) {
				++cnte;
				if(!vis[v])
				{ vis[v] = true; q.push(v); }
			}
		}
		cnte >>= 1;
		if(cnte < cntv)
			b[maxp] = true;
	}
	return !b[p];
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1, u, v; i <= n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int p = 1;
	for(; (vis[p] && !b[p]) || bfs(p); ++p);
	cout << p - 1 << endl;
	return 0;
}
