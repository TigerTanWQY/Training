#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200003;
vector<int> G[N];
bool vis[N];
int L[N], R[N], n, k = 0;

void dfs(const int& u) {
	vis[u] = true;
	L[u] = n + 1;
	R[u] = 0;
	for(const auto& v: G[u])
		if(!vis[v]) {
			dfs(v);
			L[u] = min(L[u], L[v]);
			R[u] = max(R[u], R[v]);
		}
	if(!R[u])
		L[u] = R[u] = ++k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int u, v, _ = 1; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	for(int i = 1; i <= n; ++i)
		cout << L[i] << ' ' << R[i] << '\n';
	return 0;
}