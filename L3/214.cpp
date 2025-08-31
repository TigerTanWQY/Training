#include <bits/stdc++.h>
using namespace std;

char s[1003];

void dfs(const int &l, const int &r)
{
	int x = 0, y = 0, z = 0;
	for(int i = l; i <= r; ++i)
		if(s[i] == '(')
			++x;
		else if(s[i] == ')')
			--x;
		else if(!x)
			if(s[i] == '*' || s[i] == '/')
				y = i;
			else if(s[i] == '+' || s[i] == '-')
				z = i;
	if(z)
	{
		printf("%c ", s[z]);
		dfs(l, z - 1);
		dfs(z + 1, r);
		return;
	}
	if(y)
	{
		printf("%c ", s[y]);
		dfs(l, y - 1);
		dfs(y + 1, r);
		return;
	}
	if(s[l] == '(' && s[r] == ')')
		dfs(l + 1, r - 1);
	else
	{
		for(int i = l; i <= r; ++i)
			printf("%c", s[i]);
		printf(" ");
	}
}

int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	dfs(1, n);
	return 0;
}