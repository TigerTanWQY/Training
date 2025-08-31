#include <cstdio>
#include <algorithm>
using namespace std;

int a[100003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		int c, t;
		scanf("%d%d", &c, &t);
		a[i] = a[i - 1] + c * t;
	}
	while(m--)
	{
		int v;
		scanf("%d", &v);
		printf("%llu\n", lower_bound(a + 1, a + n + 1, v) - a); // 二分查找当前歌曲
	}
	return 0;
}