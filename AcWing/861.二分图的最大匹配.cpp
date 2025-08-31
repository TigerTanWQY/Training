#include <iostream>
#include <vector>
using namespace std;

vector<int> G[503];
bool vis[503];
int match[503];

bool dfs(const int& u) {
	for(const auto& v: G[u]) {
		if(vis[v])
			continue;
		vis[v] = true;
		if(!match[v] || dfs(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n1, n2, m;
	cin >> n1 >> n2 >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	int ans = 0;
	for(int u = 1; u <= n1; ++u) {
		if(dfs(u))
			++ans;
		for(int i = 1; i <= n2; ++i)
			vis[i] = false;
	}
	cout << ans;
	return 0;
}