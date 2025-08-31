#include <bits/stdc++.h>
using namespace std;

int a[503][503];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
		for(int j = i + 1; j <= n; ++j)
		{
			scanf("%d", &a[i][j]);
			a[j][i] = a[i][j];
		}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		int mx1 = 0, mx2 = 0;
		for(int j = 1; j <= n; ++j)
			if(a[i][j] > mx1)
			{
				mx2 = mx1;
				mx1 = a[i][j];
			}
			else if(a[i][j] > mx2)
				mx2 = a[i][j];
		ans = max(ans, mx2);
	}
	printf("1\n%d", ans);
	return 0;
}