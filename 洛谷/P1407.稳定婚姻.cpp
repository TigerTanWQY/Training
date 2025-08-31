#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <bitset>
#include <array>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;

constexpr const int N = 8'003;
unordered_map<string, int> id;
array<pair<int, int>, N> cp;
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
	int n, m;
	cin >> n;
	int tot = 0;
	for(int i = 1; i <= n; ++i) {
		string boy, girl;
		cin >> boy >> girl;
		if(!id.count(boy))
			id[boy] = ++tot;
		if(!id.count(girl))
			id[girl] = ++tot;
		cp[i] = {id[boy], id[girl]};
		G[id[girl]].push_back(id[boy]);
//		G[id[boy]].push_back(id[girl]);
	}
	cin >> m;
	for(string girl, boy; m--; ) {
		cin >> girl >> boy;
		G[id[girl]].push_back(id[boy]);
//		G[id[boy]].push_back(id[girl]);
	}
	for(int u = 1; u <= tot; ++u)
		if(!dfn[u])
			dfs(u);
	for(int i = 1; i <= n; ++i)
		if(bel[cp[i].first] == bel[cp[i].second])
			cout << "Unsafe\n";
		else
			cout << "Safe\n";
	cout.flush();
	return 0;
}