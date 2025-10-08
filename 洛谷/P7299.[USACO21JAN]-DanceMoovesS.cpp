#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
unordered_set<int> ans[N];
vector<int> G[N];
int a[N], fa[N];

int fnd(int x)
{ return fa[x] == x? x: fa[x] = fnd(fa[x]); }

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		fa[i] = i;
		a[i] = i;
	}
	for(int i = 1, u, v; i <= k; ++i) {
		cin >> u >> v;
		swap(a[u], a[v]);
		G[a[u]].push_back(u);
		G[a[v]].push_back(v);
	}
	for(int i = 1; i <= n; ++i)
		G[i].push_back(i);
	for(int i = 1; i <= n; ++i)
	    fa[fnd(i)] = fnd(a[i]);
	for(int i = 1; i <= n; ++i)
		for(const auto& x: G[a[i]])
			ans[fnd(a[i])].insert(x);
	for(int i = 1; i <= n; ++i)
		cout << ans[fnd(i)].size() << '\n';
	cout.flush(); return 0;
}
