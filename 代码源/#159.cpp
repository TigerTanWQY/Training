#include <cstdio>
#include <cstring>
using namespace std;

char s[131];
int a[131], b, c[136], la, lc;

int main()
{
	scanf("%s%d", s + 1, &b);
	la = strlen(s + 1);
	for(int i = 1 ; i <= la; ++i)
		a[i] = s[la - i + 1] - '0';
	lc = la + 5;
	for(int i = 1; i <= lc; ++i)
		c[i] = a[i] * b;
	for(int i = 1; i <= lc; ++i)
	{
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	while(c[lc + 1] > 0)
		++lc;
	while(!c[lc] && lc > 1)
		--lc;
	for(int i = lc; i >= 1; --i)
		printf("%d", c[i]);
	return 0;
}