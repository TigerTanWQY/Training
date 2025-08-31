#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 2e4, MN = N + 3;
int lb(int x)
{ return x & -x; }
struct BIT {
	LL c[MN];
	void mdf(int x, LL w) {
		for(; x <= N; x += lb(x))
			c[x] += w;
	}
	LL qry(int x) {
		LL res = 0;
		for(; x > 0; x -= lb(x))
			res += c[x];
		return res;
	}
} T1, T2;
pair<int, int> a[MN];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		int j = a[i].second;
		ans += a[i].first * (T2.qry(j - 1) * j - T1.qry(j - 1) + T1.qry(N) - T1.qry(j) - (T2.qry(N) - T2.qry(j)) * j);
		T2.mdf(a[i].second, 1);
		T1.mdf(j, a[i].second);
	}
	cout << ans << endl;
	return 0;
}
