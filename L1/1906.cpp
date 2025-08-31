#include <bits/stdc++.h>
using namespace std;

char s[13];

int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	int base = 1, ans = 0;
	for(int i = len; i >= 1; --i)
	{
		ans += (s[i] - '0') * base;
		base *= 8;
	}
	printf("%d", ans);
	return 0;
}