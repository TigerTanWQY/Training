#include <bits/stdc++.h>
using namespace std;

const int MOD = 10000;
char s[1100013];
int f[1100013], v[1100013];

int dfs(const int &l, const int &r)
{
	if(f[r] >= l)
		return (dfs(l, f[r] - 1) + dfs(f[r] + 1, r)) % MOD;
	if(v[r] >= l)
		return (dfs(l, v[r] - 1) * dfs(v[r] + 1, r)) % MOD;
	int x = 0;
	for(int i = l; i <= r; ++i)
		x = x * 10 + s[i] - '0';
	return x % MOD;
}

int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; ++i)
	{
		f[i] = f[i - 1];
		v[i] = v[i - 1];
		if(s[i] == '+')
			f[i] = i;
		if(s[i] == '*')
			v[i] = i;
	}
	printf("%d", dfs(1, n));
	return 0;
}