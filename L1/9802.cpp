#include <bits/stdc++.h>
using namespace std;

constexpr const char* const s = "0123456789ABCDEF";
char ans[35];

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	if(n == 0)
	{
		cout << '0';
		return 0;
	}
	register auto len = 0;
	while(n != 0)
	{
		ans[++len] = s[n % k];
		n /= k;
	}
	for(register auto i = len; i >= 1; --i)
		cout << ans[i];
	return 0;
}