#include <bits/stdc++.h>
using namespace std;

struct
{ int x, p, c; }
a[103];

int main()
{
	int s, n, m;
	scanf("%d%d%d", &s, &n, &m);
	for(int i = 1; i <= m; ++i)
		scanf("%d%d%d", &a[i].x, &a[i].p, &a[i].c);
	int ans = 0;
	a[m + 1].x = n + 1;
	for(int i = m; i >= 1; --i)
	{
		if(s - a[i].c < 0)
		{
			int len = a[i + 1].x - a[i].x;
			if(len < 0)
				len = 0;
			ans += s * a[i].p * (1 + len);
			s = 0;
			break;
		}
		else
		{
			int len = a[i + 1].x - a[i].x;
			if(len < 0)
				len = 0;
			ans += a[i].c * a[i].p * (1 + len);
			s -= a[i].c;
		}
	}
	printf("%d", ans);
	return 0;
}