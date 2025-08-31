#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int N = 1003;
vector<pair<int, int>> E;
vector<int> G[N], V;
bool vis[N];

void dfs(const int& u, const int& fa) {
	vis[u] = true;
	for(const auto& v: G[u])
		if(!vis[v])
			dfs(v, u);
		else if(v != fa && u < v)
			E.push_back({u, v});
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int u = 1; u <= n; ++u)
		if(!vis[u]) {
			V.push_back(u);
			dfs(u, 0);
		}
	cout << E.size() << '\n';
	for(int i = 0; i < E.size(); ++i)
		cout << E[i].first << ' ' << E[i].second << ' ' << V[i] << ' ' << V[i + 1] << '\n';
	return 0;
}