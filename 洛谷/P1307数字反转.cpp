#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char n[13];

int main()
{
	scanf("%s", n + 1);
	int len = strlen(n + 1), i;
	if(n[1] == '0')
	{
		putchar('0');
		return 0;
	}
	if(n[1] == '-')
		i = 2;
	else
		i = 1;
	for(int j = len; i < j; ++i, --j)
		swap(n[i], n[j]);
	if(n[1] == '-')
	{
		i = 2;
		putchar('-');
	}
	else
		i = 1;
	for(bool flag = true; flag; ++i)
		if(n[i] != '0')
			flag = false;
	for(--i; i <= len; ++i)
		putchar(n[i]);
	return 0;
}