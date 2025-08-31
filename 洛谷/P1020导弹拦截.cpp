#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int h[100003], f[100003];

int main()
{
	int n = 0, ans = 0;
	while(scanf("%d", &h[++n]) != EOF);
	--n;
	f[0] = INT_MAX;
	for(int i = 1; i <= n; ++i)
	{
		int L = 0, R = ans + 1;
		while(L + 1 < R)
		{
			int M = (L + R) >> 1;
			if(f[M] >= h[i])
				L = M;
			else
				R = M;
		}
		int x = L + 1;
		ans = max(ans, x);
		f[x] = h[i];
	}
	printf("%d\n", ans);
	ans = 0;
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; ++i)
	{
		int L = 0, R = ans + 1;
		while(L + 1 < R)
		{
			int M = (L + R) >> 1;
			if(f[M] < h[i])
				L = M;
			else
				R = M;
		}
		int x = L + 1;
		ans = max(ans, x);
		f[x] = h[i];
	}
	printf("%d", ans);
	return 0;
}