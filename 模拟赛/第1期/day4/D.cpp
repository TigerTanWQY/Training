#include <cstdio>
using namespace std;

const int MOD = 998244353;
int a[53][53];

int main()
{
	int n, k, cntr = 0, cntc = 0;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]);
	for(int i1 = 1; i1 < n; ++i1)
		for(int i2 = i1 + 1; i2 <= n; ++i2)
		{
			bool flag = true;
			for(int j = 1; j <= n && flag; ++j)
				if(a[i1][j] + a[i2][j] >= k)
					flag = false;
			if(flag)
				++cntr;
		}
	for(int j1 = 1; j1 < n; ++j1)
		for(int j2 = j1 + 1; j2 <= n; ++j2)
		{
			bool flag = true;
			for(int i = 1; i <= n && flag; ++i)
				if(a[i][j1] + a[i][j2] >= k)
					flag = false;
			if(flag)
				++cntc;
		}
	printf("%lld", 1LL * cntr * cntc % MOD);
	return 0;
}