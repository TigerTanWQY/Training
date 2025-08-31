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
	int x = m + 1;
	for(int i = 1; ; ++i)
	{
		for(int j = 1; j <= m; ++j)
			if(c[j])
				--c[j];
		for(int j = 1; j <= m; ++j)
			if(c[j] == 0 && x <= n)
				c[j] = w[x++];
		bool ok = true;
		for(int j = 1; j <= m; ++j)
			if(c[j])
				ok = false;
		if(ok)
		{
			printf("%d", i);
			return 0;
		}
	}
	return 0;
}