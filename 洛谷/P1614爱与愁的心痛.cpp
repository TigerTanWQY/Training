#include <cstdio>
#include <algorithm>
using namespace std;

int a[3003];

int main()
{
	int n, m, tot = 0, ans;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		if(i <= m)
		{
			tot += a[i];
			ans = tot;
		}
		else
		{
			tot += a[i] - a[i - m];
			ans = min(ans, tot);
		}
	}
	printf("%d", ans);
	return 0;
}