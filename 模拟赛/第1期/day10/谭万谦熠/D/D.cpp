#include <cstdio>
#include <vector>
using namespace std;
using LL = long long;

const int MOD = 998244353;
vector<int> G[500003];

inline LL pow(const int &base, int exp)
{
	LL ret = 1;
	while(exp--)
		ret = ret * base % MOD;
	return ret;
}

int main()
{
	int n;
	LL ans = 0;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int u = 1; u <= n; ++u)
	{
		int p = G[u].size() - 1;
		ans = (ans + (pow(2, p) - 1 - p - p * (p - 1) / 2) % MOD * (n - p - 2) % MOD) % MOD;
	}
	printf("%lld", ans);
	return 0;
}