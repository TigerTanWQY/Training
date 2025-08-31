#include <iostream>
#include <vector>
#include <bitset>
#include <array>
using namespace std;

constexpr const int N = 400'003;
array<vector<int>, N> G;
array<int, N> type;

void dfs(const int& u, const int& fa) {
	for(const auto& v: G[u])
		if(v == fa || v == u)
			type[v] = 1;
		else if(!type[v]) {
			type[v] = 1;
			dfs(v, u);
		} else if(type[v] == 1)
			type[v] = 2;
		else
			type[v] = -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n, m; _T--; ) {
		cin >> n >> m;
		for(int u, v; m--; ) {
			cin >> u >> v;
			G[u].push_back(v);
		}
		type[1] = 1;
		dfs(1, 0);
		for(int u = 1; u <= n; ++u)
			cout << type[u] << ' ';
		cout << '\n';
		/** reset **/
		G.fill({});
		type.fill({});
	}
	cout.flush();
	return 0;
}