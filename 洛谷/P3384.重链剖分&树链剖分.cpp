#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
using LL = long long;

constexpr const int N = 100'003;
vector<int> G[N];
int a[N], fa[N], dep[N], sz[N], hson[N], dfn[N], top[N], rnk[N], n, idx = 0;
LL c[N];

LL lowbit(const LL& x)
{ return x & (-x); }

LL query(int x) {
	LL res = 0;
	for(; x; x -= lowbit(x))
		res += c[x];
	return res;
}

void modify(int x, const LL& d) {
	for(; x <= n; x += lowbit(x))
		c[x] += d;
}

void dfs1(const int& u) { // 求子树大小
	hson[u] = -1;
	sz[u] = 1;
	for(const auto& v: G[u])
		if(!dep[v]) {
			dep[v] = dep[u] + 1;
			fa[v] = u;
			dfs1(v);
			sz[u] += sz[v];
			if(hson[u] == -1 || sz[v] > sz[hson[u]])
				hson[u] = v;
		}
}

void dfs2(const int& u, const int& t) {
	top[u] = t;
	dfn[u] = ++idx;
	rnk[idx] = u;
	if(hson[u] == -1)
		return;
	dfs2(hson[u], t);
	for(const auto& v: G[u])
		if(v != hson[u] && v != fa[u])
			dfs2(v, v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(hson, -1, sizeof(hson));
	int q, root, P;
	cin >> n >> q >> root >> P;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		modify(i, a[i]);
	}
	for(int _ = 1, u, v; _ < q; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(root);
	dfs2(root, root);
	for(int op, u; q--; ) {
		cin >> op >> u;
		if(op == 1) {
			int v, w;
			cin >> v >> w;
			// u->v: 最短路径上的节点 += w
		} else if(op == 2) {
			int v;
			cin >> v;
			// sum u->c: 最短路径上的节点权值
		} else if(op == 3) {
			int w;
			cin >> w;
		} else
			;
	}
	cout.flush();
	return 0;
}