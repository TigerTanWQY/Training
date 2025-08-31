#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, cur, cnt, w[200010], l[200010], r[200010], fa[400010];
bool b[200010];
vector<int> g[200010];
struct node {
	int u, v, w, d;
	node() {}
	node(int x, int y, int z, int s) {
		u = x, v = y, w = z, d = s;
	}
	bool operator < (const node &y) const {
		return w < y.w;
	}
} e[400010];
void addedge(int u, int v, int w, int d) {
	e[++cnt] = node(u, v, w, d);
}
void dfs(int u, int fa) {
	l[u] = 1e18;
	bool flag = true;
	for (int i = 0; i < g[u].size(); i++) {
		if (g[u][i] == fa) continue;
		flag = false;
		dfs(g[u][i], u);
		l[u] = min(l[u], l[g[u][i]]), r[u] = max(r[u], r[g[u][i]]);
	}
	if (flag) l[u] = r[u] = ++cur;
	addedge(l[u], r[u] + 1, w[u], u);
}
int find(int u) {
	if (fa[u] == u) return u;
	else return fa[u] = find(fa[u]);
}
int kruskal() {
	sort(e + 1, e + cnt + 1);
	for (int i = 1; i <= n; i++) fa[i] = i;
	int res = 0;
	for (int i = 1; i <= cnt; i++) {
		int lst = i, now = i;
		if (find(e[now].u) != find(e[now].v)) b[e[now].d] = 1;
		while (now < cnt && e[now + 1].w == e[lst].w) {
			now++;
			if (find(e[now].u) != find(e[now].v)) b[e[now].d] = 1;
		}
		for (int j = lst; j <= now; j++)
			if (find(e[j].u) != find(e[j].v)) {
				res += e[j].w;
				fa[find(e[j].u)] = find(e[j].v);
			}
		i = now;
	}
	return res;
}
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	cout << kruskal() << " ";
	int tmp = 0;
	for (int i = 1; i <= n; i++)
		if (b[i]) tmp++;
	cout << tmp << "\n";
	for (int i = 1; i <= n; i++)
		if (b[i]) cout << i << " ";
	return 0;
}
