#include <bits/stdc++.h>
using namespace std;

int w[10003];

int main()
{
	int n, m, maxn = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &w[i]);
		if(w[i] > maxn)
			maxn = w[i];
	}
	if(m >= n)
	{
		printf("%d", maxn);
		return 0;
	}
	int l = 1, r = m, tot = 0;
	for(int j = 1; j <= n - m + 1; ++j)
	{
		sort(w + l, w + r + 1);
		if(r == n)
		{
			tot += w[r];
			printf("%d", tot);
			return 0;
		}
		for(int i = l + 1; i <= r; ++i)
			w[i] -= w[l];
		tot += w[l];
		++l;
		++r;
	}
	return 0;
}