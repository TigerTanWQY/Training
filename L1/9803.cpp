#include <bits/stdc++.h>
using namespace std;

int a[5003];

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(register auto i = 1; i <= n; ++i)
		cin >> a[i];
	register auto ans = 0;
	for(register auto i = 1; i < n; ++i)
	{
		for(register auto j = i; j < i + 2; ++j)
			for(register auto k = i + 1; k <= n; ++k)
				if(a[j] > a[k])
					swap(a[j], a[k]);
		ans += a[i] + a[i + 1];
		a[i + 1] += a[i];
	}
	cout << ans;
	return 0;
}