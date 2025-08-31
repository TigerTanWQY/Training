#include <bits/stdc++.h>
using namespace std;

int s[103][1003];
int t[103];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int id, opt;
		scanf("%d%d", &id, &opt);
		if(opt == 1)
		{
			int x;
			scanf("%d", &x);
			s[id][++t[id]] = x;
		}
		else if(opt == 2)
			if(t[id] <= 0)
				printf("error\n");
			else
			{
				printf("%d\n", s[id][t[id]]);
				--t[id];
			}
	}
	return 0;
}