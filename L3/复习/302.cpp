#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[100003];
int a[100003];
long long tot[100003];

long long dfs(const int &p)
{
	for(const auto &x: G[p])
		tot[p] += dfs(x);
	return tot[p];
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		tot[i] = a[i];
	}
	dfs(1);
	for(int i = 1; i <= n; ++i)
		printf("%lld ", tot[i]);
	return 0;
}