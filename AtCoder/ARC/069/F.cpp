#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 5;
vector<int> G[N];
int dfn[N], low[N], idx, cnt, id[N];
bool in_stk[N];
int stk[N], top;
int n, m;
int len;
int cc;

struct Node
{ int a, b, id; }
p[N];

int get(int x)
{ return x / len; }

int L(int x)
{ return max(1, x * len); }

int idp[N];

void add(int u, int l, int r) {
	if (l > r) return;
	if (r - l <= len + 5) {
		for (int i = l; i <= r; i++)
			G[u].push_back(p[i].id + n);
		return;
	}
	int L = get(l) + 1, R = get(r) - 1;
	for (int i = L; i <= R; i++)
		G[u].push_back(idp[i]);
	for (; get(l) != L; l++) G[u].push_back(p[l].id + n);
	for (; get(r) != R; r--) G[u].push_back(p[r].id + n);
}

void add2(int u, int l, int r) {
	if (l > r) return;
	if (r - l <= len + 5)
	{
		for (int i = l; i <= r; i++)
			G[u].push_back(p[i].id);
		return;
	}
	int L = get(l) + 1, R = get(r) - 1;
	for (int i = L; i <= R; i++)
		G[u].push_back(idp[i]);
	for (; get(l) != L; l++) G[u].push_back(p[l].id);
	for (; get(r) != R; r--) G[u].push_back(p[r].id);
}

void tarjan(int u) {
	dfn[u] = low[u] = ++idx;
	stk[++top] = u;
	in_stk[u] = 1;
	for (auto &j : G[u])
		if (!dfn[j]) {
			tarjan(j);
			low[u] = min(low[u], low[j]);
		} else if (in_stk[j])
			low[u] = min(low[u], dfn[j]);
	if (dfn[u] == low[u]) {
		cnt++;
		int y = 0;
		do {
			y = stk[top--];
			in_stk[y] = 0;
			id[y] = cnt;
		} while (y != u);
	}
}

bool check(int x) {
	sort(p + 1, p + n + 1, [&](const Node& x, const Node& y){return x.a < y.a;});
	sort(p + n + 1, p + n + n + 1, [&](const Node& x, const Node& y){return x.b < y.b;});
	for (int i = 1; i <= cc; i++)
	{ G[i].clear(), dfn[i] = low[i] = id[i] = in_stk[i] = 0; }
	cc = 2 * n;
	top = 0;
	for (int i = get(1); i <= get(n); i++) {
		idp[i] = ++cc;
		int l = L(i), r = min(n, L(i + 1) - 1);
		for (int j = l; j <= r; j++)
			G[cc].push_back(p[j].id + n);
	}
	for (int i = 1; i <= n; i++) {
		int l = p[i].a - x + 1, r = p[i].a + x - 1;
		int ll = lower_bound(p + 1, p + n + 1, Node(l, 0, 0), [&](const Node& x, const Node& y){return x.a < y.a;}) - p;
		int rr = upper_bound(p + 1, p + n + 1, Node(r, 0, 0), [&](const Node& x, const Node& y){return x.a < y.a;}) - p - 1;
		if (ll >= 1 && ll <= n && rr >= 1 && rr <= n && rr >= ll) {
			add(p[i].id, ll, i - 1);
			add(p[i].id, i + 1, rr);
		}
	}
	for (int i = 1; i <= n; i++) {
		int l = p[i].b - x + 1, r = p[i].b + x - 1;
		int ll = lower_bound(p + 1, p + n + 1, Node(l, 0, 0), [&](const Node& x, const Node& y){return x.a < y.a;}) - p;
		int rr = upper_bound(p + 1, p + n + 1, Node(r, 0, 0), [&](const Node& x, const Node& y){return x.a < y.a;}) - p - 1;
		if (ll >= 1 && ll <= n && rr >= 1 && rr <= n && rr >= ll)
			if (i >= ll && i <= rr) {
				add(p[i].id + n, ll, i - 1);
				add(p[i].id + n, i + 1, rr);
			} else
				add(p[i].id + n, ll, rr);
	}
	for (int i = get(0); i <= get(2 * n); i++) {
		idp[i] = ++cc;
		int l = L(i), r = min(2 * n, L(i + 1) - 1);
		for (int j = l; j <= r; j++)
			G[cc].push_back(p[j].id);
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		int l = p[i].a - x + 1, r = p[i].a + x - 1;
		int ll = lower_bound(p + n + 1, p + 2 * n + 1, Node(0, l, 0), [&](const Node& x, const Node& y){return x.b < y.b;}) - p;
		int rr = upper_bound(p + n + 1, p + 2 * n + 1, Node(0, r, 0), [&](const Node& x, const Node& y){return x.b < y.b;}) - p - 1;
		if (ll >= n && ll <= 2 * n && rr >= n && rr <= 2 * n && rr >= ll)
			if(i >= ll && i <= rr) {
				add2(p[i].id, ll, i - 1);
				add2(p[i].id, i + 1, rr);
			} else
				add2(p[i].id, ll, rr);
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		int l = p[i].b - x + 1, r = p[i].b + x - 1;
		int ll = lower_bound(p + n + 1, p + 2 * n + 1, Node(0, l, 0), [&](const Node& x, const Node& y){return x.b < y.b;}) - p;
		int rr = upper_bound(p + n + 1, p + 2 * n + 1, Node(0, r, 0), [&](const Node& x, const Node& y){return x.b < y.b;}) - p - 1;
		if (ll >= n && ll <= 2 * n && rr >= n && rr <= 2 * n && rr >= ll) {
			add2(p[i].id + n, ll, i - 1);
			add2(p[i].id + n, i + 1, rr);
		}
	}
	for (int i = 1; i <= cc; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++)
		if (id[i] == id[i + n]) return 0;
	return 1;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	len = sqrt(n);
	for (int i = 1; i <= n; i++)
	{ cin >> p[i].a >> p[i].b, p[i].id = i; }
	for (int i = 1; i <= n; i++) p[i + n] = p[i];
	int l = 0, r = (int)1e9, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
