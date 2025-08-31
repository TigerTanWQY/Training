#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = 1000007;
int a[103], f[103], tot[103];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	f[0] = 1;
    for(int i = 0; i <= m; ++i)
		tot[i] = 1;
    for(int i = 1; i <= n; ++i)
    {
    	for(int j = m; j; --j)
    	{
    		int t = j - min(a[i], j) - 1;
    		if(t < 0)
				f[j] = (f[j] + tot[j - 1]) % MOD;
    		else
				f[j] = (f[j] + tot[j - 1] - tot[t] + MOD) % MOD;
		}
		for(int j = 1; j <= m; ++j)
			tot[j] = (tot[j - 1] + f[j]) % MOD;
	}
    printf("%d", f[m]);
    return 0;
}