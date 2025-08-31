#include <iostream>
#include <vector>
using namespace std;

const int N = 200003;
vector<int> G[N];
bool vis[N];

int dfs(const int& u, const int& fa) {
	if(G[u].size() > 2)
		return u;
	for(const auto& v: G[u])
		if(v != fa)
			return dfs(v, u);
	return u;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int n, ans = 0; T--; ans = 0) {
		cin >> n;
		if(n == 1) {
			cout << "0\n";
			continue;
		}
		for(int _ = 1, u, v; _ < n; ++_) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int u = 1; u <= n; ++u)
			if(G[u].size() == 1) {
				vis[dfs(u, 0)] = true;
				++ans;
			}
		for(int u = 1; u <= n; ++u)
			if(vis[u])
				--ans;
		if(!ans)
			cout << "1\n";
		else
			cout << ans << '\n';
		for(int u = 1; u <= n; ++u) {
			G[u].clear();
			vis[u] = false;
		}
	}
	return 0;
}