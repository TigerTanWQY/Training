#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, last = 0, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		ans += max(0, x - last);
		last = x;
	}
	printf("%d", ans);
	return 0;
}