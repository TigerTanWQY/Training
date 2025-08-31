#include <bits/stdc++.h>
using namespace std;

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n;
	cin >> n;
	register auto ans = n / 3 * 2 + n % 3;
	cout << ans;
	return 0;
}