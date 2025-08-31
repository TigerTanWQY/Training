#include <cstdio>
#include <algorithm>
using namespace std;

int a[200003], c[200003];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; ++i)
	{
		scanf("%d", &a[i]);
		c[i] = a[i] - a[i - 1];
	}
	if(k % 2)
	{
		int j1 = -1, j2 = -1, minx = 0x3f3f3f3f;
		long long tot1 = 0, tot2 = 0;
		for(int i = 1; i < k; ++i)
			if(c[i] < minx)
			{
				minx = c[i];
				j1 = i;
				j2 = i + 1;
			}
		for(int i = 1; i <= k && i + 1 <= k; i += 2)
			if(i == j1)
			{
				tot1 += a[i + 2] - a[i + 1];
				i += 2;
			}
			else if(i + 1 == j1)
			{
				tot1 += a[i + 2] - a[i];
				++i;
			}
			else
				tot1 += a[i + 1] - a[i];
		for(int i = 1; i <= k && i + 1 <= k; i += 2)
			if(i == j2)
			{
				tot2 += a[i + 2] - a[i + 1];
				i += 2;
			}
			else if(i + 1 == j2)
			{
				tot2 += a[i + 2] - a[i];
				i += 2;
			}
			else
				tot2 += a[i + 1] - a[i];
		printf("%lld", min(tot1, tot2));
	}
	else
	{
		long long ans = 0;
		for(int i = 1; i <= k && i + 1 <= k; i += 2)
			ans += a[i + 1] - a[i];
		printf("%lld", ans);
	}
	return 0;
}
