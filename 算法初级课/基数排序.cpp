#include <bits/stdc++.h>
using namespace std;

constexpr const auto N = 10000003;
constexpr const auto M = 100000000;
int a[N], sa[N], v[N], r[N], c[M];
int n, m;

void cntsort(void) noexcept
{
	memset(c, 0, sizeof(c));
	for(register auto i = 1; i <= n; ++i)
		++c[v[i]];
	for(register auto i = 1; i <= m; ++i)
		c[i] += c[i - 1];
	for(register auto i = n; i >= 1; --i)
		r[sa[i]] = c[v[sa[i]]]--;
	for(register auto i = 1; i <= n; ++i)
		sa[r[i]] = i;
}

void radixsort(void) noexcept
{
	for(register auto i = 1; i <= n; ++i)
		sa[i] = i;
	register auto x = 1;
	for(register auto i = 1; i <= m; ++i, x *= 10)
	{
		for(register auto j = 1; j <= n; ++j)
			v[j] = a[j] / x % 10;
		cntsort();
	}
	for(register auto i = 1; i <= n; ++i)
		cout << a[sa[i]] << ' ';
	cout << '\n';
}

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for(register auto i = 1; i <= n; ++i)
	{
		cin >> a[i];
		m = max(m, a[i]);
	}
	radixsort();
	return 0;
}