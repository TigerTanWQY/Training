#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e5 + 3;
vector<vector<int>> vDCC;
vector<int> G[N];
stack<int> stk;
bool b[N];
int low[N], dfn[N], idx = 0;

void dfs(int u, int fa) {
	int cnt = 0;
	low[u] = dfn[u] = ++idx;
	stk.push(u);
	for(const auto& v: G[u]) {
		if(!dfn[v]) {
			++cnt;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= dfn[u]) {
				vector<int> c{u};
				while(!stk.empty()) {
					int x = stk.top();
					stk.pop();
					c.push_back(x);
					if(x == v)
						break;
				}
				vDCC.push_back(c);
			}
		} else if(v != fa)
			low[u] = min(low[u], dfn[v]);
	}
	if(!fa && !cnt)
		vDCC.push_back({u});
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int u = 1; u <= n; ++u)
		if(!dfn[u]) {
			dfs(u, 0);
			for(; !stk.empty(); stk.pop());
		}
	vector<int> ans;
	for(const auto& c: vDCC)
		for(const auto& u: c)
			if(b[u])
				ans.push_back(u);
			else
				b[u] = true;
	sort(begin(ans), end(ans));
	ans.erase(unique(begin(ans), end(ans)), cend(ans));
	cout << ans.size() << '\n';
	for(const auto& u: ans)
		cout << u << ' ';
	cout << endl; return 0;
}
