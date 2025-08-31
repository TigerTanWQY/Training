#include <bits/stdc++.h>
using namespace std;

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	register auto m = static_cast<int>(sqrt(n));
	for(register auto i = 2; i <= m; ++i)
		while(n % i == 0)
		{
			cout << i << ' ';
			n /= i;
		}
	if(n > 1)
		cout << n;
	return 0;
}