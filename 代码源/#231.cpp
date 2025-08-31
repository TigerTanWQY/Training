#include <cstdio>
#include <algorithm>
using namespace std;

int a[100003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	while(m--)
	{
		int k;
		scanf("%d", &k);
		printf("%lld\n", upper_bound(a + 1, a + n + 1, k) - a - 1);
	}
	return 0;
}