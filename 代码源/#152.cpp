#include <cstdio>
#include <cstring>
using namespace std;

char s[131];
int a[131], la;

int main()
{
	scanf("%s", s + 1);
	la = strlen(s + 1);
	for(int i = 1; i <= la; ++i)
		a[i] = s[la - i + 1] - '0';
	++a[1];
	for(int i = 1; i <= la; ++i)
	{
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	if(a[la + 1])
		++la;
	for(int i = la; i >= 1; --i)
		printf("%d", a[i]);
	return 0;
}