#include <bits/stdc++.h>
using namespace std;

char s[103];
int a[103], c[103];

int main()
{
	int b;
	scanf("%s%d", s + 1, &b);
	int la = strlen(s + 1), lc = la;
	for(int i = la; i >= 1; --i)
		a[i] = s[la - i + 1] - '0';
	int r = 0;
	for(int i = lc; i >= 1; --i)
	{
		r = r * 10 + a[i];
		c[i] = r / b;
		r %= b;
	}
	while(c[lc] == 0 && lc > 1)
		--lc;
	for(int i = lc; i >= 1; --i)
		printf("%d", c[i]);
	printf("\n%d", r);
	return 0;
}