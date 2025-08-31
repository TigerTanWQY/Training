#include <iostream>
#include <vector>
#include <bitset>
#include <stack>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 100'003;
vector<int> G[N], vDCC[N];
stack<int> stk;
bitset<N> isb;
int low[N], dfn[N], idx = 0, cnt = 0;

void dfs(const int u) {
	low[u] = dfn[u] = ++idx;
	stk.push(u);
	int child = 0;
	for(const auto& v: G[u])
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
			if(low[v] >= dfn[u]) {
				++child; ++cnt;
				if(u != 1 || child > 1)
					isb[u] = true;
				vDCC[cnt].push_back(u);
				while(!stk.empty()) {
					int x = stk.top();
					stk.pop();
					vDCC[cnt].push_back(x);
					if(x == v)
						break;
				}
			}
		} else
			low[u] = min(low[u], dfn[v]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int _T = 1, m, n = 0, ans1 = 0; cin >> m && m; cout << '\n', ++_T) {
		for(int _ = 0, u, v; _ < m; ++_) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
			n = max({n, u, v});
		}
		dfs(1);
		for(; !stk.empty(); stk.pop());
		LL ans2 = 1;
		for(int i = 1; i <= cnt; ++i) {
			int v1 = vDCC[i].size(), v2 = 0;
			for(const auto& u: vDCC[i])
				v2 += isb[u];
			if(v2 == 1) {
				++ans1;
				ans2 *= v1 - 1;
			} else if(v2 == 0) {
				ans1 += 2;
				ans2 *= 1LL * v1 * (v1 - 1) / 2;
			}
		}
		cout << "Case " << _T << ": " << ans1 << ' ' << ans2;
		/* Reset */
		for(int i = 1; i <= n; ++i) {
			G[i].clear();
			low[i] = dfn[i] = 0;
		}
		for(int i = 1; i <= cnt; ++i)
			vDCC[i].clear();
		isb.reset();
		n = idx = cnt = ans1 = 0;
	}
	cout.flush();
	return 0;
}