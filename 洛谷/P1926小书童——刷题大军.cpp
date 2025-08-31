#include <cstdio>
#include <algorithm>
using namespace std;

int a[13], v[13], w[13], f[153];

int main()
{
	int n, m, k, r, cnt = -1, ans = 0;
	scanf("%d%d%d%d", &n, &m, &k, &r);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &v[i]);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &w[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = r; j >= v[i]; --j)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	for(int i = 1; i <= r; ++i)
		if(f[i] >= k)
		{
			cnt = r - i;
			break;
		}
	for(int i = 1; i <= n; ++i)
	{
		if(cnt - a[i] >= 0)
			cnt -= a[i];
		else
			break;
		++ans;
	}
	printf("%d", ans);
	return 0;
}