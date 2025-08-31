#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[53];
int f[53][53];

int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; ++i)
	{
		f[i][i] = 1;
		for(int len = 2; len <= n; ++len)
			for(int L = 1; L <= n - len + 1; ++L)
			{
				int R = L + len - 1;
				if(s[L] == s[R])
				{
					f[L][R] = min(f[L + 1][R], f[L][R - 1]);
					continue;
				}
				for(int k = L; k < R; ++k)
					f[L][R] = min(f[L][k] + f[k + 1][R], f[L][R]);
			}
	}
	printf("%d", f[1][n]);
	return 0;
}