#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int x, y, n, ans = 0x3f3f3f3f;
	scanf("%d%d%d", &x, &y, &n);
	for(int i = 0; i <= 100 * n; i += x)
		for(int j = 0; j <= 100 * n; j += y)
			if(i / x + 3 * j / y == n)
				ans = min(ans, i + j);
	printf("%d", ans);
	return 0;
}
