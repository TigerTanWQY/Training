#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, x;
	scanf("%d%d", &n, &x);
	int last = x, maxn = x, ans = x;
	for(int i = 2; i <= n; ++i)
		ans += (maxn = max(maxn, last = (379 * last + 131) % 997));
	printf("%d", ans);
	return 0;
}