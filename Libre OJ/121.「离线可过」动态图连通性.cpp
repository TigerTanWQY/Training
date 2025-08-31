#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int inf = 2147483647;
const int Maxn = 5010, Maxm = 500010;
int n, m, tim[Maxn][Maxn], ans[Maxm];
struct Query {
	int x, y, t, id;
} q[Maxm];
int lq = 0;
struct Edge {
	int x, y, l, r;
} e[Maxm];
int le = 0;
int fa[Maxn], top = 0, dep[Maxn], p1[Maxn], p2[Maxn];
int findfa(int x) {
	return ((fa[x] == x) ? x : findfa(fa[x]));
}
void Merge(int x, int y) {
	int fx = findfa(x), fy = findfa(y);
	if (fx == fy)
		return;
	if (dep[fx] <= dep[fy]) {
		fa[fx] = fy;
		top++;
		p1[top] = fx;
		p2[top] = dep[fy];
		dep[fy] = max(dep[fy], dep[fx] + 1);
	} else {
		fa[fy] = fx;
		top++;
		p1[top] = fy;
		p2[top] = dep[fx];
		dep[fx] = max(dep[fx], dep[fy] + 1);
	}
}
void Delete(int p) {
	while (top > p) {
		dep[fa[p1[top]]] = p2[top];
		fa[p1[top]] = p1[top];
		top--;
	}
}
vector<int>h[Maxm << 1];
vector<Query>hh[Maxm << 1];
struct Seg {
	int l, r, lc, rc;
} tr[Maxm << 1];
int tot = 0, P[Maxm];
void build(int l, int r) {
	int x = ++tot;
	tr[x].l = l;
	tr[x].r = r;
	if (l == r) {
		P[l] = x;
		return;
	}
	int mid = l + r >> 1;
	tr[x].lc = tot + 1, build(l, mid);
	tr[x].rc = tot + 1, build(mid + 1, r);
}
void insert(int x, int l, int r, int id) {
	if (tr[x].l == l && tr[x].r == r) {
		h[x].push_back(id);
		return;
	}
	int lc = tr[x].lc, rc = tr[x].rc, mid = tr[x].l + tr[x].r >> 1;
	if (r <= mid)
		insert(lc, l, r, id);
	else if (l > mid)
		insert(rc, l, r, id);
	else
		insert(lc, l, mid, id), insert(rc, mid + 1, r, id);
}
void dfs(int x) {
	int now = top;
	for (int i = 0; i < h[x].size(); i++)
		Merge(e[h[x][i]].x, e[h[x][i]].y);
	if (tr[x].l == tr[x].r)
		for (int i = 0; i < hh[x].size(); i++)
			ans[hh[x][i].id] = ((findfa(hh[x][i].x) == findfa(hh[x][i].y)) ? 1 : 0);
	if (tr[x].l != tr[x].r)
		dfs(tr[x].lc), dfs(tr[x].rc);
	Delete(now);
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1, op, x, y; i <= m; i++) {
		cin >> op >> x >> y;
		if (x > y)
			swap(x, y);
		if (!op) {
			tim[x][y] = ++le;
			e[le].x = x;
			e[le].y = y;
			e[le].l = i;
			e[le].r = m;
		} else if (op == 1)
			e[tim[x][y]].r = i;
		else
			q[++lq].x = x, q[lq].y = y, q[lq].t = i, q[lq].id = lq;
	}
	for (int i = 1; i <= n; i++)
		fa[i] = i, dep[i] = 1;
	build(1, m);
	for (int i = 1; i <= le; i++)
		insert(1, e[i].l, e[i].r, i);
	for (int i = 1; i <= lq; i++)
		hh[P[q[i].t]].push_back(q[i]);
	dfs(1);
	for (int i = 1; i <= lq; i++)
		cout.put(ans[i] ? 'Y' : 'N').put('\n');
	cout.flush(); return 0;
}
