#include <iostream>
#include <atcoder/segtree>
using namespace std;
using LL = long long;

constexpr const LL INF = 0x3f3f3f3f3f3f3f3f;

LL op(const LL x, const LL y)
{ return max(x, y); }

LL init(void)
{ return 0LL; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, c, m;
	cin >> n >> c >> m;
	atcoder::segtree<LL, op, init> pre(n), suf(n);
	pre.set(0, INF);
	suf.set(0, INF);
	LL ans = INF;
	for(int i = 0; i < m; ++i) {
		int t;
		LL p;
		cin >> t >> p;
		--t;
		const LL maxn = max(pre.prod(0, t + 1) - (LL)c * t, suf.prod(t, n) + (LL)c * t) + p;
		ans = max(ans, maxn);
		pre.set(t, maxn + (LL)c * t);
		suf.set(t, maxn - (LL)c * t);
	}
	cout << ans - INF << endl;
	return 0;
}