#include <bits/stdc++.h>
using namespace std;

int *a[30003];

int main()
{
	for(int i = 0; i < 30003; ++i)
		a[i] = new int[30003];
	int n, I, J;
	scanf("%d%d%d", &n, &I, &J);
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i; j <= n - i + 1; ++j)
			a[i][j] = ++cnt;
		for(int j = i + 1; j <= n - i + 1; ++j)
			a[j][n - i + 1] = ++cnt;
		for(int j = n - i; j >= i; --j)
			a[n - i + 1][j] = ++cnt;
		for(int j = n - i; j > i; --j)
			a[j][i] = ++cnt;
	}
	printf("%d", a[I][J]);
	for(int i = 0; i < 30003; ++i)
		delete[] a[i];
	return 0;
}