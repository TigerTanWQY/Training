#include <bits/stdc++.h>
using namespace std;

char s[23];

int main()
{
	int n;
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; ++i)
	{
		if(s[i] == 'b')
			s[i] = 'd';
		else if(s[i] == 'd')
			s[i] = 'b';
		else if(s[i] == 'p')
			s[i] = 'q';
		else if(s[i] == 'q')
			s[i] = 'p';
		else if(s[i] != 'i' && s[i] != 'l' && s[i] != 'o' && s[i] != 'v' && s[i] != 'w' && s[i] != 'x')
		{
			printf("Error");
			return 0;
		}
	}
	for(int i = n; i >= 1; --i)
		printf("%c", s[i]);
	return 0;
}