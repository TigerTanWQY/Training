#include <bits/stdc++.h>
using namespace std;

register constexpr const auto N = 103;
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
	for(register auto i = 1; i <= n; ++i)
	{
		register auto t = 1;
		for(register auto j = 1; j <= n; ++j)
			if(a[j] > a[i])
				++t;
		cout << t << ' ';
	}
	return 0;
}