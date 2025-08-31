#include <bits/stdc++.h>
using namespace std;

int s[100003];
int t = 0;

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
			int k;
			scanf("%d", &k);
			printf("%d\n", s[t - k + 1]);
		}
		else if(strlen(op + 1) == 4)
		{
			int x;
			scanf("%d", &x);
			s[++t] = x;
		}
		else if(strlen(op + 1) == 3)
			--t;
	}
	return 0;
}