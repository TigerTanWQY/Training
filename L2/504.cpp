#include <bits/stdc++.h>
using namespace std;

int p[30003], c[203];

int main()
{
	int w, n;
	scanf("%d%d", &w, &n);
	for(int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		++c[x];
	}
	for(int i = 0, j = 5; j <= w; ++j)
		while(c[j]--)
			p[++i] = j;
	int i = 1, ans = n;
	for(int j = n; j > i; --j)
		if(p[i] + p[j] <= w)
		{
			++i;
			--ans;
		}
	printf("%d", ans);
	return 0;
}