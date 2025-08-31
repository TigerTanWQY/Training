#include <bits/stdc++.h>
using namespace std;

char s[103];
int a[203], b[203], c[403];

int main()
{
	scanf("%s", s + 1);
	int la = strlen(s + 1);
	for(int i = la + 1; i <= 2 * la; ++i)
		a[i] = s[la * 2 - i + 1] - '0';
	for(int i = 1; i <= la; ++i)
		a[i] = a[la * 2 - i + 1];
	la *= 2;
	scanf("%s", s + 1);
	int lb = strlen(s + 1);
	for(int i = lb + 1; i <= 2 * lb; ++i)
		b[i] = s[lb * 2 - i + 1] - '0';
	for(int i = 1; i <= lb; ++i)
		b[i] = b[lb * 2 - i + 1];
	lb *= 2;
	int lc = la + lb;
	for(int i = 1; i <= la; ++i)
		for(int j = 1; j <= lb; ++j)
			c[i + j - 1] += a[i] * b[j];
	for(int i = 1; i <= lc; ++i)
	{
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	if(c[lc + 1] > 0)
		++lc;
	while(c[lc] == 0 && lc > 1)
		--lc;
	for(int i = lc; i >= 1; --i)
		printf("%d", c[i]);
	return 0;
}