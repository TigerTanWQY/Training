#include <cstdio>
#include <climits>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if(a == 1)
	{
		printf("1");
		return 0;
	}
	long long ans = 1;
	for(; b--; ans *= a)
		if(ans * a > INT_MAX)
		{
			printf("-1");
			return 0;
		}
	printf("%lld", ans);
	return 0;
}