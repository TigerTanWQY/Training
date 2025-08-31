#include <cstdio>
using namespace std;

int main()
{
	int n, minn = 1001, maxn = -1;
	scanf("%d", &n);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		if(x < minn)
			minn = x;
		if(x > maxn)
			maxn = x;
	}
	printf("%d", maxn - minn);
	return 0;
}