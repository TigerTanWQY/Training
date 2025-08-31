#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, X;
	scanf("%d%d", &n, &X);
	int ans = X;
	for(int i = 1; i <= n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(a >= X)
			ans = min(ans, a - b);
		else
			ans = min(ans, X - b);
	}
	printf("%d", ans);
	return 0;
}