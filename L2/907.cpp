#include <bits/stdc++.h>
using namespace std;

int q[103];
int f = 1, r = 0;

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int opt, x;
		scanf("%d%d", &opt, &x);
		if(opt == 1)
			q[++r] = x;
		else
		{
			int ans = 0;
			while(q[f] != x && r - f + 1 > 0)
			{
				++f;
				++ans;
			}
			if(q[f] == x)
			{
				++f;
				++ans;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}