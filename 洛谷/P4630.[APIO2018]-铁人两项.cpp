#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N], CRT[N<<1];
stack<int> stk;
int dfn[N], low[N], sz[N<<1], f[N<<1], n, tot = 0, idx = 0, cnt = 0;
long long ans = 0;

void tarjan(int u) {
	++tot;
	dfn[u] = low[u] = ++idx;
	stk.push(u);
	sz[u] = -1;
	for(const auto& v: G[u])
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if(low[v] == dfn[u]) {
				++cnt;
				while(!stk.empty()) {
					int x = stk.top();
					stk.pop();
					CRT[x].push_back(cnt);
					CRT[cnt].push_back(x);
					++sz[cnt];
					if(x == v)
						break;
				}
				CRT[cnt].push_back(u);
				CRT[u].push_back(cnt);
				++sz[cnt];
			}
		} else
			low[u] = min(low[u], dfn[v]);
}

void dfs(int u, int fa) {
	f[u] = (u <= n);
	for(const auto& v: CRT[u])
		if(v ^ fa) {
			dfs(v, u);
			ans += 2LL * sz[u] * f[u] * f[v];
			f[u] += f[v];
		}
	ans += 2LL * sz[u] * (tot - f[u]) * f[u];
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m;
	cin >> n >> m;
	cnt = n;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i)
		if(!dfn[i]) {
			tot = 0;
			tarjan(i);
			dfs(i, 0);
		}
	cout << ans << endl;
	return 0;
}
