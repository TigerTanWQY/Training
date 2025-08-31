#include <iostream>
#include <vector>
#include <bitset>
#include <array>
#include <stack>
#include <algorithm>
using namespace std;

constexpr const int N = 103;
array<vector<int>, N> G;
stack<int> stk;
bitset<N> ins;
array<int, N> dfn, low, bel, din, dout;
int idx = 0, cnt = 0;

void dfs(const int& u) {
	dfn[u] = low[u] = ++idx;
	stk.push(u);
	ins[u] = true;
	for(const auto& v: G[u])
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(ins[v])
			low[u] = min(low[u], dfn[v]);
	if(dfn[u] == low[u]) {
		++cnt;
		while(!stk.empty()) {
			int v = stk.top();
			stk.pop();
			ins[v] = false;
			bel[v] = cnt;
			if(v == u)
				break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int u = 1; u <= n; ++u)
		for(int v; cin >> v && v; )
			G[u].push_back(v);
	for(int u = 1; u <= n; ++u)
		if(!dfn[u])
			dfs(u);
	for(int u = 1; u <= n; ++u)
		for(const auto& v: G[u])
			if(bel[u] != bel[v]) {
				++din[bel[v]];
				++dout[bel[u]];
			}
	int cnts = 0, cnte = 0;
	for(int i = 1; i <= cnt; ++i) {
		if(din[i] == 0)
			++cnts;
		if(dout[i] == 0)
			++cnte;
	}
	cout << cnts << '\n';
	if(cnt == 1)
		cout << '0';
	else
		cout << max(cnts, cnte);
	cout.flush();
	return 0;
}