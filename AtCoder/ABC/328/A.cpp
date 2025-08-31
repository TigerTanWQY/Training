#include <cstdio>
using namespace std;

int main()
{
	int n, x, tot = 0;
	scanf("%d%d", &n, &x);
	while(n--)
	{
		int y;
		scanf("%d", &y);
		if(y <= x)
			tot += y;
	}
	printf("%d", tot);
	return 0;
}