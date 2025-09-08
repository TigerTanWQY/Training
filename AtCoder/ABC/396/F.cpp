#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
int n, m, a[N], b[N], d[N];
LL c[N], f[N];

int lb(int x)
{ return x & -x; }

void mdf(int x, int w) {
	for(; x <= m; x += lb(x))
		c[x] += w;
}

LL qry(int x) {
	LL res = 0;
	for(; x >= 1; x -= lb(x))
		res += c[x];
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	LL ans = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i]; ++a[i];
		f[m - a[i] + 1] += i - b[a[i]]++ - 1;
	}
	memset(c, 0, sizeof(c));
	for(int i = n; i; --i) {
		f[m - a[i] + 1] -= (n - i - d[a[i]]);
		ans += qry(a[i] - 1); mdf(a[i], 1);
		++d[a[i]];
	}
	cout << ans << '\n';
	for(int i = 1; i < m; ++i) {
		ans += f[i];
		cout << ans << '\n';
	}
	cout.flush();
	return 0;
}
