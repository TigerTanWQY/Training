#include <bits/stdc++.h>
using namespace std;
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

constexpr const int N = 2e5 + 3;
struct SegTree {
	int val[N * 4];
	void pushdown(int u) {
		if(!val[u])
			return;
		val[ls(u)] += val[u];
		val[rs(u)] += val[u];
		val[u] = 0;
	}
	void mdf(int u, int L, int R, int qL, int qR, int w) {
		if(qL > qR)
			return;
		else if(qL <= L && qR >= R) {
			val[u] += w;
			return;
		}
		pushdown(u);
		int M = (L + R) >> 1;
		if(qL <= M)
			mdf(ls(u), L, M, qL, qR, w);
		if(qR > M)
			mdf(rs(u), M + 1, R, qL, qR, w);
	}
	int qry(int u, int L, int R, int pos) {
		if(L == R)
			return val[u];
		pushdown(u);
		int M = (L + R) >> 1;
		if(pos <= M)
			return qry(ls(u), L, M, pos);
		else
			return qry(rs(u), M + 1, R, pos);
	}
} T1, T2;
vector<int> G[N];
int dep[N], col[N], h[N], cnt;

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	for(const auto& v: G[u])
		if(v != fa)
			dfs(v, u);
	col[u] = cnt;
	h[cnt] = max(h[cnt], dep[u]);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int _ = n - 1, u, v; _--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int maxn = 0;
	for(const auto& rt: G[1]) {
		++cnt;
		dfs(rt, 1);
		maxn = max(maxn, h[cnt]);
	}
	n = cnt * maxn + 1;
	for(int i = 1, op, u, w, d; i <= m; ++i) {
		cin >> op >> u;
		if(op) {
			if(u == 1) {
				cout << T1.qry(1, 1, n, 1) + T2.qry(1, 1, n, 1) << '\n';
				continue;
			}
			int id1 = 1 + (col[u] - 1) * maxn + dep[u],
				id2 = 1 + (dep[u] - 1) * cnt + col[u];
			cout << T1.qry(1, 1, n, id1) + T2.qry(1, 1, n, id2) << '\n';
		} else {
			cin >> w >> d;
			if(u == 1) {
				T2.mdf(1, 1, n, 1, min(1 + d * cnt, n), w);
				continue;
			}
			int id1 = 1 + (col[u] - 1) * maxn + dep[u],
				id2 = 1 + (col[u] - 1) * maxn + (d - dep[u]),
				len = 1 + col[u] * maxn;
			if(dep[u] > d)
				T1.mdf(1, 1, n, id1 - d, min(id1 + d, len), w);
			else {
				T1.mdf(1, 1, n, id2 + 1, min(id1 + d, len), w);
				T2.mdf(1, 1, n, 1, min(1 + (d - dep[u]) * cnt, n), w);
			}
		}
	}
	cout.flush(); return 0;
}
