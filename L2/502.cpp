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
			if(a[j] < a[j + 1])
				swap(a[j], a[j + 1]);
	int tot = 0;
	for(int i = 1; i <= n; ++i)
	{
		tot += a[i];
		if(tot >= k)
		{
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}