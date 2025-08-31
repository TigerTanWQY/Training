#include <iostream>
#include <vector>
#include <bitset>
#include <stack>
#include <array>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;

constexpr const int N = 2'000'003;
__gnu_pbds::gp_hash_table<int, int> mp;
array<vector<int>, N> G;
stack<int> stk;
bitset<N> ins;
array<int, N> p, low, dfn, bel;
int idx = 0, cnt = 0;

void dfs(const int& u) {
	low[u] = dfn[u] = ++idx;
	stk.push(u);
	ins[u] = true;
	for(const auto& v: G[u])
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(ins[v])
			low[u] = min(low[u], dfn[v]);
	if(low[u] == dfn[u]) {
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
	int n, a, b;
	cin >> n >> a >> b;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i];
		mp[p[i]] = i;
	}
	for(int i = 1; i <= n; ++i) {
		int u = 0, v = 0;
		if(mp[a - p[i]])
			u = mp[a - p[i]];
		else
			mp.erase(a - p[i]);
		if(mp[b - p[i]])
			v = mp[b - p[i]];
		else
			mp.erase(b - p[i]);
		if(u && v) {
			G[i].push_back(u);
			G[i].push_back(v);
			G[i + n].push_back(u + n);
			G[i + n].push_back(v + n);
		} else if(u) {
			G[u + n].push_back(u);
			G[i + n].push_back(i);
		} else if(v) {
			G[v].push_back(v + n);
			G[i].push_back(i + n);
		} else {
			cout << "NO";
			return 0;
		}
	}
	for(int i = 1; i <= 2 * n; ++i)
		if(!dfn[i])
			dfs(i);
	for(int u = 1; u <= n; ++u)
		if(bel[u] == bel[u + n]) {
			cout << "NO";
			return 0;
		}
	cout << "YES\n";
	for(int u = 1; u <= n; u++)
		cout << (bel[u] > bel[u + n]) << ' ';
	cout.flush();
	return 0;
}