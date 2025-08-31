#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[10089];
int a[10089], b[10089], c[10089], la, lb, lc;

inline bool cmp()
{
	if(la != lb)
		return la > lb;
	for(int i = 1; i <= la; ++i)
		if(a[i] != b[i])
			return a[i] > b[i];
	return true;
}

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
	lc = max(la, lb);
	bool flag = !cmp();
	if(flag)
	{
		for(int i = 1; i <= lc; ++i)
			swap(a[i], b[i]);
		swap(la, lb);
	}
	for(int i = 1; i <= lc; ++i)
	{
		if(a[i] < b[i])
		{
			--a[i + 1];
			a[i] += 10;
		}
		c[i] = a[i] - b[i];
	}
	for(; !c[lc] && lc > 1; --lc);
	if(flag)
		putchar('-');
	for(int i = lc; i; --i)
		printf("%d", c[i]);
	return 0;
}