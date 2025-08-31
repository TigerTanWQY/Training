#include <cstdio>
using namespace std;
using LL = long long;

const int MOD = 1e9 + 7;
int f[200003], w[200003]{1};

int main()
{
	for(int i = 1; i <= 200000; ++i)
		w[i] = (w[i - 1] << 1) % MOD;
	int T;
	scanf("%d", &T);
	for(int n, k; T--; )
	{
		scanf("%d%d", &n, &k);
		f[0] = 1;
		for(int i = 1, v = 1; i <= k; ++i, v = 1LL * v * w[n] % MOD)
			if(n & 1)
				f[i] = 1LL * (w[n - 1] + 1) * f[i - 1] % MOD;
			else
				f[i] = (1LL * (w[n - 1] - 1) * f[i - 1] % MOD + v) % MOD;
		printf("%d\n", f[k]);
	}
	return 0;
}