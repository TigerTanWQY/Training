#include <cstdio>
using namespace std;

int main()
{
	int n, m, tot = 0, ans = 1;
	scanf("%d%d", &n, &m);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		tot += x;
		if(tot > m)
		{
			++ans;
			tot = x;
		}
	}
	printf("%d", ans);
	return 0;
}