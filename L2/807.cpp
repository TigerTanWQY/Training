#include <bits/stdc++.h>
using namespace std;

int s[103];
int t = 0;

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int opt, x;
		scanf("%d%d", &opt, &x);
		if(opt == 1)
			s[++t] = x;
		else if(opt == 2)
		{
			int ans = 0;
			while(t > 0)
			{
				int y = s[t];
				--t;
				++ans;
				if(x == y)
					break;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}