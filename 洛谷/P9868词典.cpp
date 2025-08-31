#include <cstdio>
#include <algorithm>
using namespace std;

char s[3005];
int minn[3003], maxn[3003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		minn[i] = 27;
		scanf("%s",s + 1);
		for(int j = 1; j <= m; ++j)
		{
			minn[i] = min(minn[i], s[j] - 'a' + 1);
			maxn[i] = max(maxn[i], s[j] - 'a' + 1);
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		int fl = 1;
		for(int j = 1; j <= n; ++j)
			fl &= (i == j || minn[i] < maxn[j]);
		printf("%d", fl);
	}
	return 0;
}