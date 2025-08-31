#include <bits/stdc++.h>
using namespace std;

char s[13];

int main()
{
	scanf("%s", s);
	int n = strlen(s), i = n - 1;
	if(s[0] == '-')
		printf("-");
	while(s[i] == '0')
		--i;
	for(; i >= (s[0] == '-'? 1: 0); --i)
		printf("%c", s[i]);
	return 0;
}