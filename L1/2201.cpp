#include <bits/stdc++.h>
using namespace std;

char a[13][13][103][11];

int main()
{
	int n, m, k, p, q;
	scanf("%d%d%d%d", &n, &m, &k, &p);
	while(p--)
	{
		int g, c, num;
		char s[11];
		scanf("%d%d%d%s", &g, &c, &num, s);
		strcpy(a[g][c][num], s);
	}
	scanf("%d", &q);
	while(q--)
	{
		int g, c, num;
		scanf("%d%d%d", &g, &c, &num);
		if(a[g][c][num][0] == '\0')
		{
			printf("Error\n");
			continue;
		}
		printf("%s\n", a[g][c][num]);
	}
	return 0;
}