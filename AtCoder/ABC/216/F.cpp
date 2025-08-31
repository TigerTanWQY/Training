#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = 998244353;
pair<int, int> a[5003];
int f[5003][5003];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i].first);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i].second);
	sort(a + 1, a + n + 1);
	f[1][0] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= 5000; ++j)
		{
			f[i + 1][j] = f[i][j];
			if(a[i].second <= j)
				f[i + 1][j] = (f[i + 1][j] + f[i][j - a[i].second]) % MOD;
			if(j <= a[i].first - a[i].second)
				ans = (ans + f[i][j]) % MOD;
		}
	printf("%d", ans);
	return 0;
}