#include <bits/stdc++.h>
using namespace std;

int a[200003];
int n;

int lb(const int& x) noexcept
{
	register auto L = 0, R = n + 1;
	while(L + 1 < R)
	{
		register auto M = (L + R) >> 1;
		if(a[M] < x)
			L = M;
		else
			R = M;
	}
	return L;
}

int rb(const int& x) noexcept
{
	register auto L = 0, R = n + 1;
	while(L + 1 < R)
	{
		register auto M = (L + R) >> 1;
		if(a[M] <= x)
			L = M;
		else
			R = M;
	}
	return L;
}

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int m;
	cin >> n >> m;
	for(register auto i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	while(m--)
	{
		int x;
		cin >> x;
		register auto cntl = lb(x), cntg = n - rb(x), cnte = abs(cntl + cntg - n);
		cout << cntl << ' ' << cnte << ' ' << cntg << '\n';
	}
	return 0;
}