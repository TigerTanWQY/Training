#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 5e4 + 3;
vector<pair<int, LL>> G[N];
bool vis[N];
LL a[70], f[N];

bool ist(LL x) {
	for(int i = 63; ~i; --i)
		if(x >> i & 1) {
			if(!a[i]) {
				a[i] = x;
				return true;
			}
			x ^= a[i];
		}
	return false;
}

LL qry(LL x) {
	LL res = x;
	for(int i = 63; ~i; --i)
		if((res ^ a[i]) > res)
			res ^= a[i];
	return res;
}

void dfs(int u, LL res) {
	f[u] = res;
	vis[u] = true;
	for(const auto& [v, w]: G[u])
		if(!vis[v])
			dfs(v, res ^ w);
		else
			ist(res ^ w ^ f[v]);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		LL w; cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	dfs(1, 0);
	cout << qry(f[n]) << endl;
	return 0;
}
