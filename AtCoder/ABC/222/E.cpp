#include <cstdio>
#include <vector>
using namespace std;

const int MOD = 998244353;
vector<pair<int, int>> edges[1003];
int a[103], c[1003], dp[100003]{1};

bool dfs(const int &v, const int &fa, const int &w)
{
	if(v == w)
		return true;
	for(const auto &p: edges[v])
		if(p.first != fa && dfs(p.first, v, w))
		{
			++c[p.second];
			return true;
		}
	return false;
}

int main()
{
	int n, m, k, tot = 0;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; ++i)
	{
		scanf("%d", &a[i]);
		--a[i];
	}
	for(int i = 0; i < n - 1; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		edges[u].push_back(make_pair(v, i));
		edges[v].push_back(make_pair(u, i));
	}
	for(int i = 0; i < m - 1; ++i)
		dfs(a[i], -1, a[i + 1]);
	for(int i = 0; i < n - 1; ++i)
		tot += c[i];
	if((tot + k) % 2 || tot + k < 0)
	{
		printf("0");
		return 0;
	}
	for(int i = 0; i < n - 1; ++i)
		for(int x = 1e5; x >= c[i]; --x)
			dp[x] = (dp[x] + dp[x - c[i]]) % MOD;
	printf("%d", dp[(tot + k) / 2]);
	return 0;
}