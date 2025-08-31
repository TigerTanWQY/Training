#include <iostream>
#include <unordered_set>
#include <vector>
#include <bitset>
using namespace std;

constexpr const int N = 1e5 + 3;
unordered_set<int> G[N], st;
bitset<N> vis;

void dfs(const int u) {
	vis[u] = true;
	st.erase(u);
	vector<int> res;
	for(const auto& v: st)
		if(!G[u].count(v))
			res.push_back(v);
	for(const auto& x: res)
		st.erase(x);
	for(const auto& x: res)
		dfs(x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].insert(v);
		G[v].insert(u);
	}
	for(int i = 1; i <= n; ++i)
		st.insert(i);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) {
			dfs(i);
			++ans;
		}
	cout << ans - 1 << endl;
	return 0;
}