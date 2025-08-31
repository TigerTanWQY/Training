#include <bits/stdc++.h>
using namespace std;

constexpr const auto N = 100003;
int p[2 * N];
char s[N], t[2 * N];

void manacher(void) noexcept
{
	register auto n = static_cast<int>(strlen(s + 1));
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
	auto ans = 0;
	for(register auto i = 1; i <= m; ++i)
		ans = max(ans, p[i]);
	cout << ans - 1 << '\n';
}

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> (s + 1);
	manacher();
	return 0;
}