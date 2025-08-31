#include <cstdio>
#include <cstring>
using namespace std;

char s[131];
int a[131], b[131], c[259], la, lb, lc;

int main()
{
	scanf("%s", s + 1);
	la = strlen(s + 1);
	for(int i = 1; i <= la; ++i)
		a[i] = s[la - i + 1] - '0';
	scanf("%s", s + 1);
	lb = strlen(s + 1);
	for(int i = 1; i <= lb; ++i)
		b[i] = s[lb - i + 1] - '0';
	lc = la + lb;
	for(int i = 1; i <= la; ++i)
		for(int j = 1; j <= lb; ++j)
			c[i + j - 1] += a[i] * b[j];
	for(int i = 1; i <= lc; ++i)
	{
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	while(c[lc + 1] > 0)
	{
		++lc;
		c[lc + 1] = c[lc] / 10;
		c[lc] %= 10;
	}
	while(!c[lc] && lc > 1)
		--lc;
	for(int i = lc; i >= 1; --i)
		printf("%d", c[i]);
	return 0;
}