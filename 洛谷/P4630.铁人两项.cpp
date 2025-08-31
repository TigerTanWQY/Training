#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

constexpr const int N = 100'003;
vector<int> G[N], CRT[N * 2];
stack<int> stk;
int dfn[N], low[N], n, idx = 0, cnt = 0;
int sz[N * 2], f[N * 2], tot;
long long ans = 0;

void tarjan(const int& u) {
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
					int w = stk.top();
					stk.pop();
					CRT[w].push_back(cnt);
					CRT[cnt].push_back(w);
					++sz[cnt];
					if(w == v)
						break;
				}
				CRT[cnt].push_back(u);
				CRT[u].push_back(cnt);
				++sz[cnt];
			}
		} else
			low[u] = min(low[u], dfn[v]);
}

void dfs(const int& u, const int& fa) {
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m;
	cnt = n;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int u = 1; u <= n; ++u)
		if(!dfn[u]){
			tot = 0;
			tarjan(u);
			dfs(u, 0);
		}
	cout << ans;
	cout.flush();
	return 0;
}