#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<pair<int, int>> G[N];
pair<int, int> e[N];
bool b1[N], b2[N];
int d[N], c[N], idx = 0;

void dfs(int u) {
	b1[u] = true; c[u] = idx;
	for(const auto& [v, id]: G[u])
		if(!b1[v]) {
			b2[id] = true;
			dfs(v);
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		G[u].push_back({v, i});
		G[v].push_back({u, i});
		e[i] = {u, v};
	}
	for(int i = 1; i <= n; ++i) {
		if(b1[i])
			continue;
		++idx;
		dfs(i);
		d[idx] = i;
	}
	cout << idx - 1 << '\n';
	memset(b1, 0, sizeof(b1));
	int tmp = 2;
	for(int i = 1, j = 1; i <= m && j < idx; ++i) {
		if(b2[i])
			continue;
		if(c[e[i].first] == 1 || b1[c[e[i].first]]) {
			for(; b1[tmp]; ++tmp);
			cout << i << ' ' << e[i].second << ' ' << d[tmp];
			b1[c[d[tmp++]]] = true;
		} else {
			cout << i << ' ' << e[i].second << ' ' << d[1];
			b1[c[e[i].first]] = true;
		}
		cout.put('\n'); ++j;
	}
	cout.flush();
	return 0;
}
