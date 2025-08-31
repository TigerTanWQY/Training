#include <bits/stdc++.h>
using namespace std;

int a[10003], f[10003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int maxn = 0;
	for(int i = 1; i <= n; ++i)
	{
		f[i] = 1;
		for(int j = 1; j < i; ++j)
			if(a[j] < a[i])
				f[i] = max(f[i], f[j] + 1);
		maxn = max(maxn, f[i]);
	}
	printf("%d", maxn);
	return 0;
}