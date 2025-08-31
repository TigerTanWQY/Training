#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
using LL = long long;

char s[200003];
int c[200003], m;

int main()
{
	long long k;
	scanf("%s%lld", s + 1, &k);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; ++i)
		if(s[i] == 'Y')
			c[++m] = i;
	int L = 1, ans = 0;
	LL x = k;
	for(int R = 1; R <= m; ++R)
	{
		int M = (L + R) >> 1;
		x -= (c[R] - c[M] - (R - M));
		while(x < 0)
		{
			M = (L + R + 1) >> 1;
			x += (c[M] - c[L] - (M - L));
			++L;
		}
		ans = max(ans, R - L + 1);
	}
	printf("%d", ans);
	return 0;
}