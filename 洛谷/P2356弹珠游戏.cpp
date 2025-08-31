#include <cstdio>
#include <algorithm>
using namespace std;

int a[1003][1003];

int main()
{
	int n, ans = 0, flag = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j])
				++flag;
		}
	if(flag == n * n)
	{
		printf("Bad Game!");
		return 0;
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			int tot = 0;
			if(!a[i][j])
			{
				for(int k = 1; k <= n; ++k)
					tot += a[k][j];
				for(int k = 1; k <= n; ++k)
					tot += a[i][k];
				ans = max(ans, tot);
			}
		}
	printf("%d", ans);
	return 0;
}