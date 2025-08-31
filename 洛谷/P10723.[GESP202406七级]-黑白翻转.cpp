#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N];
bool a[N];
int ans = 0;

bool dfs(int u, int fa) {
	bool res = 0;
	for(const auto& v: G[u])
		if(v != fa && dfs(v, u))
			res = 1;
	if(!a[u] && res)
		++ans;
	return (a[u] || res);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int rt = 0;
	for(int i = 1; !rt && i <= n; ++i)
		if(a[i])
			rt = i;
	dfs(rt, 0);
	cout << ans << endl;
	return 0;
}
