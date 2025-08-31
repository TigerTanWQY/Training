#include <bits/stdc++.h>
using namespace std;

int a[503];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m, minx = INT_MAX, ans = 0;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", &a[i]);
			minx = min(minx, a[i]);
		}
		for(int i = 1; i <= n; ++i)
			ans += min(abs(minx - a[i]), (int)ceil((minx - a[i]) / 2.0));
		printf("%d\n", ans);
	}
	return 0;
}