#include <cstdio>
using namespace std;

int main()
{
	int n, p, ans = 0;
	scanf("%d%d", &n, &p);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		if(x < p)
			++ans;
	}
	printf("%d", ans);
	return 0;
}