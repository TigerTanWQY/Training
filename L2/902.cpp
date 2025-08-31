#include <bits/stdc++.h>
using namespace std;

char q[103];
int f = 1, r = 0;

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
			char name[13];
			scanf("%s", name + 1);
			q[++r] = name[1];
		}
		else
		{
			for(int i = 1; i <= 10 && f <= r; ++i)
				printf("%c ", q[f++]);
			printf("\n");
		}
	}
	return 0;
}