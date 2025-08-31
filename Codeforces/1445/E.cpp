#include <bits/stdc++.h>
using namespace std;

constexpr const int INF = 0x3f3f3f3f, N = 1e6 + 6;
struct UndoDSU {
	int n;
	stack<pair<int, int>> stk;
	vector<int> fa, sz;
	void init(int _n) {
		n = _n;
		for(; !stk.empty(); stk.pop());
		fa.resize(n + 3); sz.resize(n + 2);
		for(int i = 0; i <= n; ++i)
		{ fa[i] = i; sz[i] = 1; }
	}
	int fnd(int x)
	{ return x == fa[x]? x: fnd(fa[x]); }
	void mrge(int x, int y) {
		x = fnd(x); y = fnd(y);
		if(x == y)
			return;
		if(sz[x] > sz[y])
			swap(x, y);
		fa[x] = y; sz[y] += sz[x];
		stk.push({x, y});
	}
	void undo() {
		if(stk.empty())
			return;
		auto [fx, fy] = stk.top();
		stk.pop();
		fa[fx] = fx; sz[fy] -= sz[fx];
	}
};
map<pair<int, int>, vector<int>> q;
bitset<N> vis;
int c[N], a[N], b[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	UndoDSU dsu;
	dsu.init(n * 2 + 3);
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	for(int i = 1; i <= m; ++i)
		cin >> a[i] >> b[i];
	for(int i = 1; i <= m; ++i)
		if(c[a[i]] == c[b[i]]) {
			int fx = dsu.fnd(a[i]), fy = dsu.fnd(b[i]);
			if(fx == fy)
				vis[c[a[i]]] = true;
			else
			{ dsu.mrge(a[i], b[i] + n); dsu.mrge(b[i], a[i] + n); }
		}
	for(int i = 1; i <= m; ++i)
		if(c[a[i]] != c[b[i]] && !vis[c[a[i]]] && !vis[c[b[i]]]) {
			int Lc = c[a[i]], Rc = c[b[i]];
			if(Lc > Rc)
				swap(Lc, Rc);
			q[{Lc, Rc}].push_back(i);
		}
	long long ans = 0;
	for(const auto& [_, __]: q) {
		int lst = dsu.stk.size();
		for(const auto& i: __) {
			int x = a[i], y = b[i], fx = dsu.fnd(x), fy = dsu.fnd(y);
			if(fx == fy) {
				--ans;
				break;
			}
			dsu.mrge(x, y + n);
			dsu.mrge(y, x + n);
		}
		for(; dsu.stk.size() > lst; dsu.undo());
	}
	long long cnt = k - vis.count();
	ans += cnt * (cnt - 1) / 2;
	cout << ans << endl;
	return 0;
}
