#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;

int op(int a, int b) { return max(a, b); }
int e() { return -1e9; }
int mapping(int f, int x) { return f + x; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto& e : a)
		cin >> e;
	vector<int> f(n, 0);
	vector<int> suml(n), sumr(n);
	int cnt = 0;
	vector<int> vis(n + 1, 0);
	for(int i = 0; i < n; ++i) {
		if(++vis[a[i]] == 1)
			++cnt;
		suml[i] = cnt;
	}
	vis = vector<int>(n + 1, 0);
	cnt = 0;
	for(int i = n - 1; i >= 0; --i) {
		if(++vis[a[i]] == 1)
			++cnt;
		sumr[i] = cnt;
	}
	atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> seg(n);
	vector<int> last(n + 1, -1);
	for(int i = 0; i < n; ++i) {
		seg.apply(last[a[i]] == -1? 0: last[a[i]], i, 1);
		f[i] = seg.prod(0, i);
		seg.set(i, suml[i]);
		last[a[i]] = i;
	}
	int ans = 0;
	for(int i = 1; i < n - 1; ++i)
		ans = max(ans, f[i] + sumr[i + 1]);
	cout << ans << endl;
	return 0;
}
