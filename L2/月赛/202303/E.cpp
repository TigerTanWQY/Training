#include <bits/stdc++.h>
using namespace std;

char s[13];
int num1[13], num2[13];

int main()
{
	int p1, p2;
	scanf("%d%d", &p1, &p2);
	scanf("%s", s + 1);
	int len1 = strlen(s + 1);
	for(int i = 1; i <= len1; ++i)
	{
		char tmp = s[len1 - i + 1];
		if(tmp <= '9')
			num1[i] = tmp - '0';
		else
			num1[i] = tmp - 'A' + 10;
	}
	scanf("%s", s + 1);
	int len2 = strlen(s + 1);
	for(int i = 1; i <= len2; ++i)
	{
		char tmp = s[len2 - i + 1];
		if(tmp <= '9')
			num2[i] = tmp - '0';
		else
			num2[i] = tmp - 'A' + 10;
	}
	long long x = 0, y = 0;
	long long cnt = 1;
	for(int i = 1; i <= len1; ++i)
	{
		x += num1[i] * cnt;
		cnt *= p1;
	}
	cnt = 1;
	for(int i = 1; i <= len2; ++i)
	{
		y += num2[i] * cnt;
		cnt *= p2;
	}
	printf("%lld", x + y);
	return 0;
}