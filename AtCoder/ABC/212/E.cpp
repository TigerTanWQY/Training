#include <cstdio>
#include <vector>
using namespace std;
using LL = long long;

const int MOD = 998244353;
vector<int> G[5003];
LL f[5003], f2[5003];

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	while(m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	f[1] = 1;
	while(k--)
	{
		LL tot = 0;
		for(int j = 1; j <= n; ++j)
			tot += f[j];
		for(int j = 1; j <= n; ++j)
		{
			f2[j] = tot - f[j];
			for(const auto &p: G[j])
				f2[j] -= f[p];
			f2[j] %= MOD;
		}
		for(int j = 1; j <= n; ++j)
			f[j] = f2[j];
	}
	printf("%lld", f[1] % MOD);
	return 0;
}