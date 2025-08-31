#include <cstdio>
#include <algorithm>
using namespace std;

int a[503][503];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
		for(int j = i + 1; j <= n; ++j)
		{
			scanf("%d", &a[i][j]);
			a[j][i] = a[i][j];
		}
	for(int i = 1, maxx1, maxx2; i <= n; ++i)
	{
		maxx1 = 0;
		maxx2 = 0;
		for(int j = 1; j <= n; ++j)
			if(a[i][j] > maxx1)
			{
				maxx2 = maxx1;
				maxx1 = a[i][j];
			}
			else if(a[i][j] > maxx2)
				maxx2 = a[i][j];
		ans = max(ans, maxx2);
	}
	printf("1\n%d", ans);
	return 0;
}