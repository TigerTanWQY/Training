#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
char s[1003];

int dfs(const int &l, const int &r)
{
	int x = 0, y = 0, z = 0;
	for(int i = l; i <= r; ++i)
		if(s[i] == '(')
			++x;
		else if(s[i] == ')')
			--x;
		else if(!x)
			if(s[i] == '*')
				y = i;
			else if(s[i] == '+' || s[i] == '-')
				z = i;
	if(z)
		if(s[z] == '+')
			return (dfs(l, z - 1) + dfs(z + 1, r)) % MOD;
		else
			return (dfs(l, z - 1) - dfs(z + 1, r) + MOD) % MOD;
	if(y)
		return 1LL * dfs(l, y - 1) * dfs(y + 1, r) % MOD;
	if(s[l] == '(' && s[r] == ')')
		return dfs(l + 1, r - 1);
	else
	{
		int v = 0;
		for(int i = l; i <= r; ++i)
			v = v * 10 + s[i] - '0';
		return v;
	}
}

int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	printf("%d", dfs(1, n));
	return 0;
}