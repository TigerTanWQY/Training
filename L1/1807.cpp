#include <bits/stdc++.h>
using namespace std;

char s[103];
int a[103], b[103], c[103];

int main()
{
	scanf("%s", s + 1);
	int la = strlen(s + 1);
	for(int i = 1; i <= la; ++i)
		a[i] = s[la - i + 1] - '0';
	scanf("%s", s + 1);
	int lb = strlen(s + 1);
	for(int i = 1; i <= lb; ++i)
		b[i] = s[lb - i + 1] - '0';
	int lc = max(la, lb);
	for(int i = 1; i <= lc; ++i)
	{
		c[i] += a[i] - b[i];
		if(c[i] < 0)
		{
			c[i] += 10;
			--c[i + 1];
		}
	}
	while(c[lc] == 0 && lc > 1)
		--lc;
	for(int i = lc; i >= 1; --i)
		printf("%d", c[i]);
	return 0;
}