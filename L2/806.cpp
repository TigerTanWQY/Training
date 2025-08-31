#include <bits/stdc++.h>
using namespace std;

int a[103][5];
int t = 0;

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int opt;
		scanf("%d", &opt);
		if(opt == 1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			a[++t][1] = x;
			a[t][2] = y;
		}
		else if(opt == 2)
			if(t <= 0)
				printf("error\n");
			else
			{
				printf("%d %d\n", a[t][1], a[t][2]);
				--t;
			}
	}
	return 0;
}