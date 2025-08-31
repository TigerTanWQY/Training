#include <cstdio>
#include <climits>
#include <vector>
using namespace std;
using LL = long long;

vector<int> G[200003];
int w[200003], h[200003];

void dfs(const int &p)
{
	for(const auto &x: G[p])
		if(!h[x])
		{
			h[x] = h[p] + 1;
			dfs(x);
		}
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int n;
	LL ans = INT_MAX;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &w[i]);
	for(int i = 1, u, v; i < n; ++i)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			h[j] = 0;
		h[i] = 1;
		dfs(i);
		LL tot = 0;
		for(int j = 1; j <= n; ++j)
			tot += 1LL * w[j] * (h[j] - 1);
		ans = min(ans, tot);
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
