#include <bits/stdc++.h>
using namespace std;

struct Ticket
{
	int t, price;
	bool used;
} a[100003];
int m = 0;

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int g, p, t;
		scanf("%d%d%d", &g, &p, &t);
		if(g == 0) //地铁
		{
			++m;
			ans += p;
			a[m].t = t;
			a[m].price = p;
		}
		else //公交车
		{
			int id = -1;
			for(int j = m; j >= 1; --j)
			{
				if(a[j].t < t - 45)
					break;
				if(a[j].price >= p && !a[j].used)
					id = j;
			}
			if(id != -1)
				a[id].used = true;
			else
				ans += p;
		}
	}
	printf("%d", ans);
	return 0;
}