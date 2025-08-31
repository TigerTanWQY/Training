#include <bits/stdc++.h>
using namespace std;

int v[100003], d[100003];
long long a[100003];

int main()
{
	int n;
	long long k;
	scanf("%d%lld", &n, &k);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &v[i], &d[i]);
		a[i] = a[i - 1] + v[i];
	}
	int ans = 1000000001;
	for(int i = 1; i <= n; ++i)
		for(int l = 1; l <= n - i + 1; ++l)
			if(a[i + l] - a[i] >= k)
			{
				int dan = 0;
				for(int j = i; j <= i + l - 1; ++j)
					dan = max(dan, d[j]);
				ans = min(ans, dan);
			}
	printf("%d", ans);
	return 0;
}