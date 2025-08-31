#include <bits/stdc++.h>
using namespace std;

register constexpr const auto N = 1003;
int a[N][N];
int h[N], l[N];

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(register auto i = 1; i <= n; ++i)
		for(register auto j = 1; j <= n; ++j)
			cin >> a[i][j];
	for(register auto i = 1; i <= n; ++i)
		for(register auto j = 2; j <= n; ++j)
			h[i] += abs(a[i][j] - a[i][j - 1]);
	for(register auto j = 1; j <= n; ++j)
		for(register auto i = 2; i <= n; ++i)
			l[j] += abs(a[i][j] - a[i - 1][j]);
	register auto flag = false;
	register auto x = 0, minn = 10000001;
	for(register auto i = 1; i <= n; ++i)
	{
		if(h[i] <= minn)
		{
			minn = h[x = i];
			flag = false;
		}
		if(l[i] <= minn)
		{
			minn = l[x = i];
			flag = true;
		}
	}
	cout << "di" << ' ' << x << ' ' << (flag? "lie": "hang") << '\n';
	cout << minn << '\n';
	if(flag)
		for(register auto i = 1; i <= n; ++i)
			cout << a[i][x] << ' ';
	else
		for(register auto j = 1; j <= n; ++j)
			cout << a[x][j] << ' ';
	return 0;
}