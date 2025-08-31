#include <cstdio>
#include <algorithm>
using namespace std;

int a[300003], c[300003];

int main()
{
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
	{
		long long R = a[i] + m;
		auto cit1 = lower_bound(a + 1, a + n + 1, a[i]), cit2 = lower_bound(a + 1, a + n + 1, R);
		ans = max((long long)ans, cit2 - cit1);
	}
	printf("%d", ans);
	return 0;
}