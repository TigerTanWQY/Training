#include <bits/stdc++.h>
using namespace std;

constexpr const auto N = 100003;
int a[N], c[N];
auto ans = 0LL;

void msort(const int& l, const int& r) noexcept
{
	if(l >= r)
		return;
	auto m = (l + r) / 2;
	msort(l, m);
	msort(m + 1, r);
	register auto p1 = l, p2 = m + 1, tot = 0;
	while(p1 <= m && p2 <= r)
		if(a[p1] <= a[p2])
			c[++tot] = a[p1++];
		else
		{
			ans += m - p1 + 1;
			c[++tot] = a[p2++];
		}
	while(p1 <= m)
		c[++tot] = a[p1++];
	while(p2 <= r)
		c[++tot] = a[p2++];
	for(register auto i = 1; i <= tot; ++i)
		a[i + l - 1] = c[i];
}

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(register auto i = 1; i <= n; ++i)
		cin >> a[i];
	msort(1, n);
	cout << ans;
	return 0;
}