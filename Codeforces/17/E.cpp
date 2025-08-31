#include <bits/stdc++.h>
using namespace std;

constexpr const auto MOD = 51123987;
constexpr const auto N = 2000003;
int p[2 * N], f[N], v[N];
char s[N], t[2 * N];
int n;

void manacher(void) noexcept
{
	register auto m = 0;
	t[++m] = '$';
	for(register auto i = 1; i <= n; ++i)
	{
		t[++m] = s[i];
		t[++m] = '$';
	}
	register auto M = 0, R = 0;
	for(register auto i = 1; i <= m; ++i)
	{
		if(i > R)
			p[i] = 1;
		else
			p[i] = min(p[2 * M - i], R - i + 1);
		while(i - p[i] > 0 && i + p[i] <= m && t[i - p[i]] == t[i + p[i]])
			++p[i];
		if(i + p[i] - 1 > R)
		{
			M = i;
			R = i + p[i] - 1;
		}
	}
	register auto x = 0LL;
	for(register auto i = 1; i <= m; ++i)
	{
		register auto l = (i - p[i] + 2) / 2, r = i / 2;
		++v[l];
		--v[r + 1];
		l = (i + 1) / 2;
		r = (i + p[i] - 2) / 2;
		++f[l];
		--f[r + 1];
		x += r - l + 1;
	}
	for(register auto i = 1; i <= n + 1; ++i)
		v[i] += v[i - 1];
	for(register auto i = 1; i <= n; ++i)
		f[i] += f[i - 1];
	for(register auto i = n - 1; i >= 1; --i)
	{
		v[i] += v[i + 1];
		v[i] %= MOD;
	}
	register auto ans = 0LL;
	if(x & 1)
		ans = x % MOD * ((x - 1) / 2 % MOD) % MOD;
	else
		ans = x / 2 % MOD * ((x - 1) % MOD) % MOD;
	for(register auto i = 1; i <= n; ++i)
	{
		ans -= 1LL * f[i] * v[i + 1] % MOD;
		if(ans < 0)
			ans += MOD;
	}
	printf("%lld\n", ans);
}

int main(void) noexcept
{
	scanf("%d%s", &n, s + 1);
	manacher();
	return 0;
}