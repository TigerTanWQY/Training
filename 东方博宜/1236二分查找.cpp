#include <bits/stdc++.h>
using namespace std;

int a[1000003];
int n;

int calc(const int& x) noexcept
{
	register auto L = 0, R = n + 1;
	while(L + 1 < R)
	{
		register auto M = (L + R) >> 1;
		if(a[M] < x)
			L = M;
		else if(a[M] > x)
			R = M;
		else
			return M;
	}
	return -1;
}

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int x;
	cin >> n;
	for(register auto i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> x;
	cout << calc(x);
	return 0;
}