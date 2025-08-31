#include <bits/stdc++.h>
using namespace std;

char s[103];
int a[103], c[104];

int main()
{
	int b;
	scanf("%s%d", s + 1, &b);
	int la = strlen(s + 1);
	for(int i = 1; i <= la; ++i)
		a[i] = s[la - i + 1] - '0';
	int lc = la + 1;
	c[1] = a[1] + b;
	for(int i = 2; i <= lc; ++i)
	{
		c[i] = a[i] + c[i - 1] / 10;
		c[i - 1] %= 10;
	}
	if(c[lc + 1] > 0)
		++lc;
	while(c[lc] == 0 && lc > 1)
		--lc;
	for(int i = lc; i >= 1; --i)
		printf("%d", c[i]);
	return 0;
}