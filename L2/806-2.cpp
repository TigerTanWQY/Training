#include <bits/stdc++.h>
using namespace std;

struct Node
{ int x, y; }
s[103];
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
			Node x;
			scanf("%d%d", &x.x, &x.y);
			s[++t] = x;
		}
		else
			if(t <= 0)
				printf("error\n");
			else
			{
				printf("%d %d\n", s[t].x, s[t].y);
				--t;
			}
	}
	return 0;
}