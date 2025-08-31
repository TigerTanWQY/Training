#include <bits/stdc++.h>
using namespace std;

char s[10];

int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1), base = 1, ans = 0;
	for(int i = len; i >= 1; --i)
	{
		char tmp = s[i];
		if(tmp >= 'A')
			ans += (tmp - 'A' + 10) * base;
		else
			ans += (tmp - '0') * base;
		base *= 16;
	}
	printf("%d", ans);
	return 0;
}