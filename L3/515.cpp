#include <bits/stdc++.h>
using namespace std;

char s[503];
int f[503][503];

int main()
{
	int n;
	scanf("%d%s", &n, s + 1);
	for(int d = 1; d < n; ++d)
		for(int i = 1; i <= n - d; ++i)
		{
			int j = i + d;
			if((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))
				f[i][j] = max(f[i][j], f[i + 1][j - 1] + 2);
			for(int k = i; k < j; ++k)
				f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]);
		}
	printf("%d", f[1][n]);
	return 0;
}