#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int a[10000003], b[10000003];

int main()
{
	freopen("body.in", "r", stdin);
	freopen("body.out", "w", stdout);
	int n, K;
	scanf("%d%d", &n, &K);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	for(int len = 0; len < n; ++len)
		for(int l = 1; l <= n - len; ++l)
		{
			int r = l + len, totv = INT_MAX, totb = 0;
			for(int i = l; i <= r; ++i)
			{
				totv = min(totv, a[i]);
				totb = max(totb, b[i]);
			}
			totv += K;
			if(totv <= totb)
			{
				printf("%d", len + 1);
				return 0;
			}
		}
	printf("So bad!");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
