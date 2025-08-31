#include <bits/stdc++.h>
using namespace std;

int q[103][1003];
int f[103], r[103];

int main()
{
	for(int i = 0; i < 103; ++i)
		f[i] = 1;
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
			q[id][++r[id]] = x;
		}
		else
			if(r[id] - f[id] + 1 <= 0)
				printf("error\n");
			else
			{
				printf("%d\n", q[id][f[id]]);
				++f[id];
			}
	}
	return 0;
}