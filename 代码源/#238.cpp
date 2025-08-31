#include <cstdio>
using namespace std;

int main()
{
	int a, b, ans = 0;
	scanf("%d%d", &a, &b);
	for(int i = a; i <= b; ++i)
	{
		int x1 = i / 10000, x2 = i / 1000 % 10, x3 = i / 100 % 10, x4 = i / 10 % 10, x5 = i % 10;
		ans += (x1 == 7) + (x2 == 7) + (x3 == 7) + (x4 == 7) + (x5 == 7);
	}
	printf("%d", ans);
	return 0;
}