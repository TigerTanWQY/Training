#include <bits/stdc++.h>
using namespace std;

int q[10003];
int f = 1, r = 0;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		q[++r] = i;
	int now = 0;
	while(r - f + 1 > 0)
	{
		++now;
		if(now == m)
		{
			now = 0;
			printf("%d ", q[f]);
		}
		else
			q[++r] = q[f];
		++f;
	}
	return 0;
}