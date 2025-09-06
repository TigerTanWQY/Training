#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> G[N];
int d[N], f[20][N];

void dfs(int u) {
	;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		++d[u]; ++d[v];
	}
	for(int i = 1; i <= n; ++i)
		if(d[i] == 1) {
			;
		} else if(d[i] == 4) {
			;
		}
	cout << endl;
	return 0;
}
