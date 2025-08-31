#include <bits/stdc++.h>
using namespace std;

register constexpr const auto N = 1000 + 3;
int a[N];

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(register auto i = 1; i <= n; ++i)
		cin >> a[i];
	register auto maxn = 1, l = 1;
	for(register auto i = 2; i <= n; ++i)
	{
		if(a[i] == a[i - 1])
			++l;
		else
			l = 1;
		if(l > maxn)
			maxn = l;
	}
	cout << maxn;
	return 0;
}