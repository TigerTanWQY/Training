#include <cstdio>
using namespace std;

int main()
{
	int n, l, ans = 0;
	scanf("%d%d", &n, &l);
	for(int i = 1, x; i <= n; ++i)
	{
		scanf("%d", &x);
		if(x >= l)
			++ans;
	}
	printf("%d", ans);
	return 0;
}