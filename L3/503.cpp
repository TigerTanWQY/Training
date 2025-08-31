#include <bits/stdc++.h>
using namespace std;

int a[1004], f[1004];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	a[n + 1] = 1e9 + 1;
	for(int i = 1; i <= n + 1; ++i)
	{
		f[i] = 1;
		for(int j = 1; j < i; ++j)
			if(a[i] > a[j])
				f[i] = max(f[i], f[j] + 1);
	}
	printf("%d", f[n + 1] - 1);
	return 0;
}