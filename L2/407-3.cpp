#include <bits/stdc++.h>
using namespace std;

int w[10003], c[103];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &w[i]);
	for(int i = 1; i <= m; ++i)
		c[i] = w[i];
	for(int i = m + 1; i <= n; ++i)
	{
		int pos = 1;
		for(int j = 1; j <= m; ++j)
			if(c[j] < c[pos])
				pos = j;
		c[pos] += w[i];
	}
	int ans = 0;
	for(int i = 1; i <= m; ++i)
		ans = max(ans, c[i]);
	printf("%d", ans);
	return 0;
}