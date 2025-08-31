#include <bits/stdc++.h>
using namespace std;

char s[103];
int a[103];

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int b, c;
	cin >> s >> b >> c;
	register auto n = static_cast<int>(strlen(s));
	for(register auto i = 0; i < n; ++i)
		a[i] = s[n - i - 1] - '0';
	a[0] += b + c;
	for(register auto i = 0; i < n - 1; ++i)
	{
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	if(a[n - 1] >= 10)
	{
		a[n] += a[n - 1] / 10;
		a[n - 1] %= 10;
	}
	for(register auto i = n - 1; i >= 0; --i)
		cout << a[i];
	return 0;
}