#include <cstdio>
#include <algorithm>
using namespace std;

int a[5003];

int main()
{
	int l, n, maxt = 0, mint = 0;
	scanf("%d%d", &l, &n);
	if(n == 0)
	{
		printf("0 0");
		return 0;
	}
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		mint = max(min(a[i], l + 1 - a[i]), mint);
	maxt = max(l + 1 - a[1], a[n]);
	printf("%d %d", mint, maxt);
	return 0;
}