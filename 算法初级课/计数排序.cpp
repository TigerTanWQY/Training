#include <bits/stdc++.h>
using namespace std;

constexpr const auto N = 100000003;
constexpr const auto M = 100000000;
int n, m, a[N], c[M], r[N];

void cntsort(void) noexcept
{
	memset(c, 0, sizeof(c));
	for(register auto i = 1; i <= n; ++i)
		++c[a[i]];
	for(register auto i = 1; i <= m; ++i)
		for(register auto j = 1; j <= c[i]; ++j)
			cout << i << ' '; //排序结果
	cout << '\n';
	for(register auto i = 2; i <= m; ++i)
		c[i] += c[i - 1];
	for(register auto i = n; i >= 1; --i)
		r[i] = c[a[i]]--;
	for(register auto i = 1; i <= n; ++i)
		cout << r[i] << ' ';
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
	cntsort();
	return 0;
}