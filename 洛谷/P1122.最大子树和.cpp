#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 16'003;
vector<int> G[N];
int a[N], f[N];

void dfs(const int u, const int fa) {
	f[u] = a[u];
	for(const auto& v: G[u])
		if(v != fa) {
			dfs(v, u);
			if(f[v] > 0)
				f[u] += f[v];
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	cout << *max_element(f + 1, f + n + 1);
	cout.flush();
	return 0;
}