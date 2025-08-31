#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1003;
vector<int> G[N];
bool vis[N][N];
int f[N], pos[N];

int dfs(const int& u) {
	if(~f[u])
		return f[u];
	f[u] = 0;
	for(const auto& v: G[u])
		f[u] = max(f[u], dfs(v));
	return ++f[u];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, ans = 0;
	cin >> n >> m;
	memset(vis, true, sizeof vis);
	memset(f, -1, sizeof f);
	for(int x; m--; ) {
		for(int i = 1; i <= n; ++i) {
			cin >> x;
			pos[x] = i;
		}
		for(int u = 1; u <= n; ++u)
			for(int v = 1; v <= n; ++v)
				vis[u][v] &= pos[u] < pos[v];
	}
	for(int u = 1; u <= n; u++)
		for(int v = 1; v <= n; v++)
			if(vis[u][v])
				G[u].push_back(v);
	for(int u = 1; u <= n; ++u)
		ans = max(ans, dfs(u));
	cout << ans;
	return 0;
}