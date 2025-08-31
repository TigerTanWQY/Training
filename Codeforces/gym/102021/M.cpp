#include <bits/stdc++.h>
using namespace std;
/*
Input:
3 5 3
1 3 2 1 3
2 4 5 4 4
2 1 3 2 2
1 1 3 2
2 4 2 2
1 4 3 4

Output:
2
4
3
*/
constexpr const int dxy[4][3]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
constexpr const int N = 503, N2 = N * N;
vector<pair<int, int>> G[N];
vector<tuple<int, int, int>> e;
int a[N][N], fa[N2], sz[N2], dfn[N2], nxt[N2], idx = 0, n, m;

struct SegmentTree {
	struct Seg
	{ int L, R, val, t; }
	seg[N2 << 2];
	int a[N2], n;

	inline void update(const int u)
	{ seg[u].val = seg[u * 2].val + seg[u * 2 + 1].val; }

	inline void settag(const int u, const int L, const int R, const int t) {
		seg[u].val += t * (R - L + 1);
		seg[u].t += t;
	}

	inline void pushdown(const int u) {
		if(seg[u].t == 0)
			return;
		const int M = (seg[u].L + seg[u].R) >> 1;
		settag(u * 2, seg[u].L, M, seg[u].t);
		settag(u * 2 + 1, M + 1, seg[u].R, seg[u].t);
		seg[u].t = 0;
	}

	void buildTree(const int u, const int L, const int R) {
		seg[u] = {L, R, 0, 0};
		if(L == R) {
			seg[u].val = a[L];
			seg[u].t = 0;
			return;
		}
		const int M = (L + R) >> 1;
		buildTree(u * 2, L, M);
		buildTree(u * 2 + 1, M + 1, R);
		update(u);
	}

	int query(const int u, const int L, const int R) {
		if(L <= seg[u].L && seg[u].R <= R)
			return seg[u].val;
		pushdown(u);
		const int M = (seg[u].L + seg[u].R) >> 1;
		if(R <= M)
			return query(u * 2, L, R);
		else if(L > M)
			return query(u * 2 + 1, L, R);
		else
			return query(u * 2, L, M) + query(u * 2 + 1, M + 1, R);
	}

	void modify(const int u, const int L, const int R, const int w) {
		if(L <= seg[u].L && seg[u].R <= R) {
			settag(u, seg[u].L, seg[u].R, w);
			return;
		}
		const int M = (seg[u].L + seg[u].R) >> 1;
		pushdown(u);
		if(R <= M)
			modify(u * 2, L, R, w);
		else if(L > M)
			modify(u * 2 + 1, L, R, w);
		else {
			modify(u * 2, L, M, w);
			modify(u * 2 + 1, M + 1, R, w);
		}
		update(u);
	}
} link[21];

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void Kruskal() {
	sort(e.begin(), e.end());
	e.erase(unique(e.begin(), e.end()), e.cend());
	for(int i = 0; i <= n * m; ++i)
		fa[i] = i;
	for(auto [w, u, v]: e) {
		int fu = fnd(u), fv = fnd(v);
		if(fu == fv)
			continue;
		fa[fv] = fu;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
}

void dfs(const int u) { // ???????
	sz[u] = 1;
	int maxs = 0, id = u;
	for(const auto& [v, w]: G[u])
		if(v != fa[u]) {
			fa[v] = u;
			dfs(v);
			sz[u] += sz[v];
			if(sz[v] > maxs) {
				maxs = sz[v];
				id = v;
			}
		}
	nxt[u] = id;
}

int query(const int u, const int v) {
	return link[nxt[u]].query(1, v, v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	auto chg = [](const int& x, const int &y)
	{ return n * (x - 1) + y; };
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			e.push_back({a[i][j], 0, chg(i, j)});
			e.push_back({a[i][j], chg(i, j), 0});
			for(int k = 0; k < 4; ++k) {
				int tx = i + dxy[k][0], ty = j + dxy[k][1];
				if(1 <= tx && tx <= n && 1 <= ty && ty <= m) {
					e.push_back({0, chg(i, j), chg(tx, ty)});
					e.push_back({0, chg(tx, ty), chg(i, j)});
				}
			}
		}
	Kruskal(); // MST
	memset(fa, 0, sizeof(fa));
	dfs(1); // 树剖
	for(int x1, y1, x2, y2; q--; cout.put('\n')) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << query(chg(x1, y1), chg(x2, y2));
	}
	cout.flush();
	return 0;
}
