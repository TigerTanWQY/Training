#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100003], b[100003];

int main()
{
	int m, n;
	long long ans = 0;
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	sort(a + 1, a + m + 1);
	for(int i = 1; i <= n; ++i)
		if(b[i] <= a[1])
			ans += a[1] - b[i];
		else
			ans += min(abs(*(upper_bound(a + 1, a + m + 1, b[i]) - 1) - b[i]), abs(*upper_bound(a + 1, a + m + 1, b[i]) - b[i]));
	printf("%lld", ans);
	return 0;
}