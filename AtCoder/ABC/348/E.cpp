#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define int int_fast32_t
using LL = int_fast64_t;

const int N = 100003;
vector<int> G[N];
int c[N];
LL sc[N], sd[N], f[N];

pair<LL, LL> dfs(const int& u, const int& fa) {
	for(const auto& v: G[u])
		if(v != fa) {
			auto tmp = dfs(v, u);
			LL tc = tmp.first, td = tmp.second;
			sc[u] += tc;
			sd[u] += td;
		}
	sd[u] += sc[u];
	sc[u] += c[u];
	return {sc[u], sd[u]};
}

void bdfs(const int& u, const int& fa, const LL& fac, const LL& fad) {
	f[u] = sd[u] + fad;
	for (const int& v: G[u])
		if (v != fa) {
			const LL tc = fac + sc[u] - sc[v], td = fad + sd[u] - sd[v] - sc[v] + tc;
			bdfs(v, u, tc, td);
		}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	dfs(1, 0);
	bdfs(1, 0, 0, 0);
	cout << *min_element(f + 1, f + n + 1);
    return 0;
}