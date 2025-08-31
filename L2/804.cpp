#include <bits/stdc++.h>
using namespace std;

char s[100003];
int t = 0;

int main()
{
	int n;
	scanf("%d%*c", &n);
	while(n--)
	{
		char op;
		scanf("%c", &op);
		if(s[t] == op)
			--t;
		else
			s[++t] = op;
	}
	for(int i = 1; i <= t; ++i)
		printf("%c", s[i]);
	return 0;
}