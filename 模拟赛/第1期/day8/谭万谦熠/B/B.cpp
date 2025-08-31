#include <cstdio>
using namespace std;

int a[100003];

inline int gcd(int x, int y)
{
	while(y)
	{
		int tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1, l = 1, g = a[1]; i <= n; ++i)
	{
		g = gcd(g, a[i]);
		if(g == 1)
		{
			++ans;
			g = a[l = i + 1];
			continue;
		}
	}
	if(!ans)
		ans = -1;
	printf("%d", ans);
	return 0;
}