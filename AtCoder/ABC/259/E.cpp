#include <bits/stdc++.h>
using namespace std;

int c[200003];
map<int, int> x, v;

int main()
{
	int n, ans = 1;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int m;
		scanf("%d", &m);
		while(m--)
		{
			int p, e;
			scanf("%d%d", &p, &e);
			if(x[p] == e)
				v[p] = 0;
			if(x[p] < e)
			{
				v[p] = i;
				x[p] = e;
			}
		}
	}
	for(const auto &t: v)
		c[t.second] = 1;
	for(int i = 1; i <= n; ++i)
		ans += c[i];
	printf("%d", min(ans, n));
	return 0;
}