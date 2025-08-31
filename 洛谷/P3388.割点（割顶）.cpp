#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

constexpr const int N = 500'003;
vector<vector<int>> vDCC;
vector<int> G[N];
stack<int> stk;
int low[N], dfn[N], idx;

void dfs(const int& u, const int& fa) {
	int child = 0;
	low[u] = dfn[u] = ++idx;
	stk.push(u);
	for(const auto& v: G[u]) {
		if(!dfn[v]) {
			++child;
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
	if(fa == 0 && child == 0)
		vDCC.push_back({u});
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
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
	unordered_set<int> st;
	set<int> ans;
	for(const auto& c: vDCC)
		for(const auto& u: c)
			if(st.count(u))
				ans.insert(u);
			else
				st.insert(u);
	cout << ans.size() << '\n';
	for(const auto& u: ans)
		cout << u << ' ';
	cout.flush();
	return 0;
}