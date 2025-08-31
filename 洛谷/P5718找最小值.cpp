#include <cstdio>
using namespace std;

int main()
{
	int n, ans = 1001;
	scanf("%d", &n);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		if(x < ans)
			ans = x;
	}
	printf("%d", ans);
	return 0;
}