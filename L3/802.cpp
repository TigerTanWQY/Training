#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int f[1003][1003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		f[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % MOD;
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j <= i; ++j)
			printf("%d ", f[i][j]);
		printf("\n");
	}
	return 0;
}