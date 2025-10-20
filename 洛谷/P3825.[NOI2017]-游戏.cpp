#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
int n, d, m, a1[N], b1[N], ecnt, nxt[N], adj[N], go[N], dfn[N], low[N],
times, num, bel[N], top, stk[N], cyx[N];
char s[N], a2[N], b2[N], orz[N];
bool ins[N], flg;

void add_edge(int u, int v) {
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}
int neg(int x) {return x > n? x - n: x + n;}
int tran(int x, char c) {
	if (s[x] == 'a') return c == 'B'? x: x + n;
	if (s[x] == 'b' || s[x] == 'c') return c == 'A'? x: x + n;
	if (c == 'C') return x + n; return x;
}
void Tarjan(int u) {
	dfn[u] = low[u] = ++times; ins[stk[++top] = u] = 1;
	for (int e = adj[u], v; e; e = nxt[e])
		if (!dfn[v = go[e]]) {
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (ins[v]) low[u] = min(low[u], dfn[v]);
	if (dfn[u] == low[u]) {
		int v; bel[u] = ++num; ins[u] = 0;
		while (v = stk[top--], v != u) bel[v] = num, ins[v] = 0;
	}
}
bool solve() {
	int i; ecnt = times = num = 0;
	for (i = 1; i <= (n << 1); i++) bel[i] = adj[i] = dfn[i] = 0;
	for (i = 1; i <= m; i++)
		if (s[a1[i]] != 'x' && s[b1[i]] != 'x') {
			if (a2[i] == s[a1[i]] - 32) continue;
			int u = tran(a1[i], a2[i]), v;
			if (b2[i] == s[b1[i]] - 32) {add_edge(u, neg(u)); continue;}
			v = tran(b1[i], b2[i]); add_edge(u, v);
			add_edge(neg(v), neg(u));
		} else {
			char o = s[a1[i]], p = s[b1[i]];
			int u, v, x = cyx[a1[i]], y = cyx[b1[i]];
			if (o == 'x' && p == 'x') {
				if (a2[i] == orz[x]) continue;
				u = tran(a1[i], a2[i]), v;
				if (b2[i] == orz[y]) {add_edge(u, neg(u)); continue;}
				v = tran(b1[i], b2[i]); add_edge(u, v);
				add_edge(neg(v), neg(u));
			} else if (o == 'x' && p != 'x') {
				if (a2[i] == orz[x]) continue;
				u = tran(a1[i], a2[i]), v;
				if (b2[i] == s[b1[i]] - 32) {add_edge(u, neg(u)); continue;}
				v = tran(b1[i], b2[i]); add_edge(u, v);
				add_edge(neg(v), neg(u));
			} else {
				if (a2[i] == s[a1[i]] - 32) continue;
				u = tran(a1[i], a2[i]), v;
				if (b2[i] == orz[y]) {add_edge(u, neg(u)); continue;}
				v = tran(b1[i], b2[i]); add_edge(u, v);
				add_edge(neg(v), neg(u));
			}
		}
	for (i = 1; i <= (n << 1); i++) if (!dfn[i]) Tarjan(i);
	for (i = 1; i <= n; i++) if (bel[i] == bel[i + n]) return 0;
	for (i = 1; i <= n; i++)
		if (bel[i] < bel[i + n]) {
			if (s[i] == 'a') cout.put('B');
			else if (s[i] == 'b' || s[i] == 'C') cout.put('A');
			else if (orz[cyx[i]] == 'A') cout.put('B');
			else cout.put('A');
		} else {
			if (s[i] == 'a' || s[i] == 'b') cout.put('C');
			else if (s[i] == 'c') cout.put('B');
			else if (orz[cyx[i]] == 'A') cout.put('C');
			else cout.put('B');
		}
	return 1;
}
void dfs(int dep) {
	if (dep > d) {
		if (!flg) flg = solve();
		if (flg) exit(0);
		return;
	}
	orz[dep] = 'A'; dfs(dep + 1);
	orz[dep] = 'B'; dfs(dep + 1);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int i;
	cin >> n >> i >> s >> m;
	for (i = n; i; --i)
		swap(s[i], s[i-1]);
	for (i = 1; i <= n; i++) if (s[i] == 'x') cyx[i] = ++d;
	for (i = 1; i <= m; i++)
		cin >> a1[i] >> a2[i] >> b1[i] >> b2[i];
	dfs(1);
	if (!flg) cout << "-1";
	cout << endl; return 0;
}
