#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> G[N];
bitset<N> vis;
int a[N];

void dfs(const int u) {
	vis[u] = false;
	for(const auto& v: G[u])
		if(vis[v])
			dfs(v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(!vis[a[i]]) {
			vis[a[i]] = true;
			++ans;
		}
	}
	for(int i = 1, j = n; i < j; ++i, --j) {
		G[a[i]].push_back(a[j]);
		G[a[j]].push_back(a[i]);
	}
	for(int i = 1; i <= 2e5; ++i)
		if(vis[i]) {
			dfs(i);
			--ans;
		}
	cout << ans << endl;
	return 0;
}
