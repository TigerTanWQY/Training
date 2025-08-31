#include <bits/stdc++.h>
using namespace std;

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	long long a, b;
	cin >> n >> a;
	register auto ans = 0;
	for(register auto i = 1; i < n; ++i)
	{
		cin >> b;
		register auto x = a, y = b;
		register auto z = 0;
		while(x != 0 || y != 0)
		{
			z = (x % 10 + y % 10 + z) / 10;
			ans += z;
			x /= 10;
			y /= 10;
		}
		a += b;
	}
	cout << ans;
	return 0;
}