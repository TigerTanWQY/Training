#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct Node {
	int u, v, w1, w2;
	bool operator<(const Node& A) const
	{ return w2 < A.w2; }
} e[50003], a[50003];
int n;
struct {
	int fa[203];
	void init(void)
	{ iota(fa, fa + n + 1, 0); }
	int fnd(int x) {
		if(fa[x] != x)
			fa[x] = fnd(fa[x]);
		return fa[x];
	}
	void mrge(int u, int v) {
		u = fnd(u); v = fnd(v);
		if(u == v)
			return;
		fa[v] = u;
	}
	bool same(int u, int v)
	{ return fnd(u) == fnd(v); }
} S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, K1, K2;
	cin >> n >> m >> K1 >> K2;
	for(int i = 1, u, v, w1, w2; i <= m; ++i) {
		cin >> u >> v >> w1 >> w2;
		e[i] = {u, v, w1, w2};
	}
	sort(e + 1, e + m + 1);
	LL ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1, tot = 0; i <= m; ++i) {
		int pos = ++tot;
		for(; pos - 1 && a[pos - 1].w1 > e[i].w1; --pos)
			a[pos] = a[pos - 1];
		a[pos] = e[i];
		S.init();
		int cnt = 0, maxS = 0;
		for(int j = 1; j <= tot; ++j) {
			const auto& [u, v, w1, _] = a[j];
			if(!S.same(u, v)) {
				S.mrge(u, v);
				a[++cnt] = a[j];
				maxS = max(maxS, w1);
			}
		}
		if(cnt == n - 1)
			ans = min(ans, (LL)maxS * K1 + (LL)e[i].w2 * K2);
		tot = cnt;
	}
	cout << (ans == 0x3f3f3f3f3f3f3f3f? -1: ans) << endl;
	return 0;
}
