#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	while(m--)
	{
		int q;
		scanf("%d", &q);
		auto it = lower_bound(a + 1, a + n + 1, q);
		if(*it != q)
			printf("-1 ");
		else
			printf("%llu ", it - a);
	}
	return 0;
}