#include <bits/stdc++.h>
using namespace std;

int a[100003];

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(register auto i = 1; i <= n; ++i)
		cin >> a[i];
	while(m--)
	{
		int l, x;
		cin >> l >> x;
		if(a[l] > x)
		{
			cout << "-1\n";
			continue;
		}
		;
	}
	return 0;
}