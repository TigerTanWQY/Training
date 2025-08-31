#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> G[N], ans;
int ed;

void dfs(const int u, const int fa) {
	ans.push_back(u);
	if(u == ed) {
		for(const auto& x: ans)
			cout << x << ' ';
		cout << endl;
		exit(0);
		return;
	}
	for(const auto& v: G[u])
		if(v != fa)
			dfs(v, u);
	ans.pop_back();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, st;
	cin >> n >> st >> ed;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(st, 0);
	return 0;
}