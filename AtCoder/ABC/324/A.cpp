#include <cstdio>
using namespace std;

int main()
{
	int n, x;
	scanf("%d%d", &n, &x);
	--n;
	for(int y; n--; )
	{
		scanf("%d", &y);
		if(y != x)
		{
			printf("No");
			return 0;
		}
		x = y;
	}
	printf("Yes");
	return 0;
}