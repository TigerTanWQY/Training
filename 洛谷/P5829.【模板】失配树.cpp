#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e6 + 3;
vector<int> G[N];
bool vis[N];
char s[N];
int kmp[N], h[N], dep[N], fa[24][N];

void dfs(int u) {
	dep[u] = dep[fa[0][u]] + 1;
	for(int i = 1; i <= 21; ++i)
		fa[i][u] = fa[i-1][fa[i-1][u]];
	for(const auto& v: G[u]) {
		if(v == fa[0][u])
			continue;
		fa[0][v] = u;
		dfs(v);
	}
}
int LCA(int u, int v) {
	if(dep[u] < dep[v])
		swap(u, v);
	for(int i = 21; ~i; --i)
		if(dep[fa[i][u]] >= dep[v])
			u = fa[i][u];
	if(u == v)
		return u;
	for(int i = 21; ~i; --i)
		if(fa[i][u] != fa[i][v]) {
			u = fa[i][u];
			v = fa[i][v];
		}
	return fa[0][u];
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> s;
	const int n = strlen(s);
	for(int i = n; i; --i)
		swap(s[i], s[i-1]);
	for (int i = 2, j = 0; i <= n; ++i) {
		while(j && s[i] != s[j+1])
			j = kmp[j];
		if(s[i] == s[j+1])
			++j;
		kmp[i] = j;
	}
	for(int i = n; i; --i)
		if(!vis[i]) {
			vis[i] = true;
			for(int j = i; ; ) {
				if(!j)
					break;
				G[j].push_back(kmp[j]);
				G[kmp[j]].push_back(j);
				j = kmp[j];
				if(vis[j])
					break;
				vis[j] = true;
			}
		}
	fa[0][0] = n + 1;
	dfs(0);
	int _T;
	cin >> _T;
	for(int u, v; _T--; cout.put('\n')) {
		cin >> u >> v;
		int k = LCA(u, v);
		if(k == u || k == v)
			k = fa[0][k];
		cout << k;
	}
	cout.flush(); return 0;
}
