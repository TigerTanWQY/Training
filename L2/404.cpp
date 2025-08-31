#include <bits/stdc++.h>
using namespace std;

char s[16];

int main()
{
	scanf("%s", s + 1);
	int x = 0, tot = 0;
	for(int i = 1; i < 13; ++i)
		if(s[i] != '-')
			tot += (++x) * (s[i] - '0');
	tot %= 11;
	char c;
	if(tot == 10)
		c = 'X';
	else
		c = tot + '0';
	if(s[13] == c)
		printf("Right");
	else
	{
		s[13] = c;
		printf("%s", s + 1);
	}
	return 0;
}