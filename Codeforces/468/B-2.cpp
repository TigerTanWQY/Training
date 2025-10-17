#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
unordered_map<int, int> mp;
vector<int> G[N];
stack<int> stk;
bool ins[N];
int p[N], low[N], dfn[N], bel[N], idx = 0, cnt = 0;

void dfs(int u) {
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
			int v = stk.top(); stk.pop();
			ins[v] = false;
			bel[v] = cnt;
			if(v == u)
				break;
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, a, b;
	cin >> n >> a >> b;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i];
		mp[p[i]] = i;
	}
	for(int i = 1; i <= n; ++i) {
		int u = 0, v = 0;
		if(mp.count(a - p[i]))
			u = mp[a - p[i]];
		if(mp.count(b - p[i]))
			v = mp[b - p[i]];
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
			cout << "NO" << endl;
			return 0;
		}
	}
	for(int i = 1; i <= n * 2; ++i)
		if(!dfn[i])
			dfs(i);
	for(int i = 1; i <= n; ++i)
		if(bel[i] == bel[i + n]) {
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES\n";
	for(int i = 1; i <= n; ++i)
		cout << (bel[i] > bel[i + n]) << ' ';
	cout << endl; return 0;
}
