#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;

mt19937_64 rd(random_device{}());
constexpr const int N = 1e5 + 3;
vector<pair<int, int>> G[N];
bool vis[N];
int dfn[N], idx = 0;
ULL w[500003], p[64];

void dfs(int u, int fm) {
	dfn[u] = ++idx;
	vis[u] = true;
	ULL tot = 0;
	for(const auto& [v, i]: G[u]) {
		if(i >> 1 == fm)
			continue;
		if(vis[v]) {
			if(dfn[v] < dfn[u])
				w[i >> 1] = rd();
		} else
			dfs(v, i >> 1);
		tot ^= w[i >> 1];
	}
	w[fm] = tot;
}
bool ist(ULL x) {
	for(int i = 63; ~i; --i)
		if(x >> i & 1)
			if(p[i])
				x ^= p[i];
    		else {
				p[i] = x;
				return true;
			}
	return false;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, _q;
	cin >> n >> m;
	for(int i = 1, u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back({v, ++i});
		G[v].push_back({u, ++i});
	}
	dfs(1, 0);
	cin >> _q;
	for(ULL lst = 0ULL; _q--; cout.put('\n')) {
		int k;
		cin >> k;
		bool flg = true;
		for(int i = 1, x; i <= k; ++i) {
			cin >> x;
			x ^= lst;
			flg &= ist(w[x]);
		}
		memset(p, 0, sizeof p);
		lst += flg;
		cout << (flg? "Connected": "Disconnected");
	}
	cout.flush(); return 0;
}
