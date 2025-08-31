#include <bits/stdc++.h>
using namespace std;

int a[1003];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i < n; ++i)
		for(int j = 1; j <= n - i; ++j)
			if(a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(ans + a[i] > k)
		{
			printf("%d", i - 1);
			return 0;
		}
		ans += a[i];
	}
	printf("%d", n);
	return 0;
}