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
		if(op == '(' || op == '[')
			s[++t] = op;
		else if(op == ')')
			if(s[t] == '(')
				--t;
			else
			{
				printf("No");
				return 0;
			}
		else if(op == ']')
			if(s[t] == '[')
				--t;
			else
			{
				printf("No");
				return 0;
			}
	}
	if(t > 0)
		printf("No");
	else
		printf("Yes");
	return 0;
}