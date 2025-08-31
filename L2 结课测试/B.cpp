#include <bits/stdc++.h>
using namespace std;

int a[34], b[34];

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int ans = 0;
		for(int i = n; i >= 1; --i) //将b[i]从大到小排序
			scanf("%d%d", &a[i], &b[i]);
		a[n + 1] = INT_MAX; //第n+1种宝石
		b[n + 1] = 1;
		for(int i = 1; i <= n + 1; ++i) //优先装b[i]较大的
		{
			int x = min(a[i], m / b[i]); //最多有a[i]个
			ans += x;
			m -= b[i] * x;
		}
		printf("%d\n", ans);
	}
	return 0;
}