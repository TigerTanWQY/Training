#include <bits/stdc++.h>
using namespace std;

int q[100003];
int f = 1, r = 0;

int main()
{
	int m;
	scanf("%d", &m);
	while(m--)
	{
		char op[8];
		scanf("%s", op + 1);
		if(op[1] == 'q')
		{
			int x;
			scanf("%d", &x);
			printf("%d\n", q[f + x - 1]);
		}
		else if(strlen(op + 1) == 4)
		{
			int x;
			scanf("%d", &x);
			q[++r] = x;
		}
		else
			++f;
	}
	return 0;
}