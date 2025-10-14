#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N], c, ans1, ans2;
bool vis[N], col[N];
int dep[N], cnt[N], K, mx, S, T;

void dfs(int u) {
	c.push_back(u);
	dep[u] = c.size();
	for(const auto& v: G[u]) {
		if(!dep[v])
			dfs(v);
		else if(dep[v] == dep[u] - 1)
			++cnt[u];
		if(dep[v] < dep[u] - 1 || cnt[u] == 2) {
			int t = dep[u] - dep[v] + 1;
			if(t <= K) {
				cout << "2\n" << t << '\n';
				for(int k = dep[v] - 1; k < dep[u]; ++k)
					cout << c[k] << ' ';
				cout << endl; exit(0);
				return;
			} else if(t <= mx) {
				mx = t;
				S = u; T = v;
			}
		}
	}
	c.pop_back();
}

void dfs1(int u) {
	c.push_back(u);
	dep[u] = c.size();
	if(u == T) {
		cout.put('1').put('\n');
		for(int k = 0; k < K; k += 2)
			cout << c[k] << ' ';
		cout << endl; exit(0);
		return;
	}
	for(const auto& v: G[u]) {
		if(u == S && v == T)
			continue;
		if(!dep[v])
			dfs1(v);
	}
	c.pop_back();
}

void dfs2(int u) {
	vis[u] = true;
	if(col[u])
		ans1.push_back(u);
	else
		ans2.push_back(u);
	for(const auto& v: G[u])
		if(!vis[v]) {
			col[v] = !col[u];
			dfs2(v);
		}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m >> K;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	mx = n;
	dfs(1);
	if(S) {
		memset(dep, 0, sizeof dep);
		dfs1(S);
		return 0;
	}
	cout.put('1').put('\n');
	dfs2(1);
	int t = (K + 1) / 2;
	if(ans1.size() >= t)
		for(int i = 0; i < t; ++i)
			cout << ans1[i] << ' ';
	else
		for(int i = 0; i < t; ++i)
			cout << ans2[i] << ' ';
	cout << endl; return 0;
}
