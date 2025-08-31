#include <bits/stdc++.h>
using namespace std;

int s[100003];
int t = 0;

void push(int x)
{
	s[++t] = x;
}

void pop()
{
	--t;
}

int top()
{
	return s[t];
}

int main()
{
	int m;
	scanf("%d", &m);
	while(m--)
	{
		char op[7];
		scanf("%s", op + 1);
		if(strlen(op + 1) == 4)
		{
			int x;
			scanf("%d", &x);
			push(x);
		}
		else if(op[1] == 'p')
			pop();
		else if(op[1] == 't')
			printf("%d\n", top());
	}
	return 0;
}