#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 998244353;
char s[3003];
int f[3003][3003];

int main()
{
	scanf("%s", s);
	int n = strlen(s);
	f[0][0] = 1;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
		{
			if(s[i] != ')')
				f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j]) % MOD;
			if(j != 0 && s[i] != '(')
				f[i + 1][j - 1] = (f[i + 1][j - 1] + f[i][j]) % MOD;
		}
	printf("%d", f[n][0]);
	return 0;
}