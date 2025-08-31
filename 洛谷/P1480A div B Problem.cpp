#include <cstdio>
#include <cstring>
using namespace std;
using LL = long long;

char s[5003];
int a[5003], c[5003], la, lc;
LL b;

int main()
{
	scanf("%s%lld", s + 1, &b);
	la = strlen(s + 1);
	for(int i = 1; i <= la; ++i)
		a[i] = s[la - i + 1] - '0';
	lc = la;
	LL r = 0;
	for(int i = la; i; --i)
	{
		r = r * 10 + a[i];
		c[i] = r / b;
		r %= b;
	}
	for(; !c[lc] && lc > 1; --lc);
	for(int i = lc; i; --i)
		printf("%d", c[i]);
	return 0;
}