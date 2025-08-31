#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200003;
const int M = 20;
vector<int> G[N];
int a[N], d[N], f[M + 3][N];

void dfs(const int& u, const int& fa) {
	d[u] = d[fa] + 1;
	f[0][u] = fa;
	for(int i = 1; i <= M; ++i)
		f[i][u] = f[i - 1][f[i - 1][u]];
	for(const auto& v: G[u])
		if(v != fa)
			dfs(v, u);
}

int LCA(int u, int v) {
	if(d[u] < d[v])
		swap(u, v);
	for(int i = M; i >= 0; --i) {
		if(d[f[i][u]] >= d[v])
			u = f[i][u];
		if(u == v)
			return u;
	}
	for(int i = M; i >= 0; --i)
		if(f[i][u] != f[i][v]) {
			u = f[i][u];
			v = f[i][v];
		}
	return f[0][u];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n;
	for(int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	cin >> q;
	for(int tot; q--; ) {
		cin >> tot;
		bool flag = true;
		int u = 0, v = 0, dis, lca;
		for(int j = 1; j <= tot; ++j) {
			cin >> a[j];
			if(d[a[j]] > d[u])
				u = a[j];
		}
		for(int j = 1; j <= tot; ++j) {
			if(a[j] == u)
				continue;
			if(v == 0) {
				v = a[j];
				lca = LCA(a[j], u);
				dis = d[a[j]] + d[u] - 2 * d[lca];
			} else {
				int tx = d[a[j]] + d[u] - 2 * d[LCA(a[j], u)];
				if(tx > dis) {
					dis = tx;
					v = a[j];
					lca = LCA(a[j], u);
				}
			}
		}
		for(int j = 1; j <= tot && flag; ++j) {
			if(a[j] == v || a[j] == u)
				continue;
			if(d[a[j]] < d[lca])
				flag = false;
			else {
				int tx = LCA(a[j], u), ty = LCA(a[j], v);
				if(!(tx == a[j] || ty == a[j]))
					flag = false;
			}
		}
		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}