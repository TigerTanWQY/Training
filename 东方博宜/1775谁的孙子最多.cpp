#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[10003];

int main()
{
	int n, maxn = 0, maxi = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int m;
		scanf("%d", &m);
		for(int _ = 1; _ <= m; ++_)
		{
			int x;
			scanf("%d", &x);
			G[i].push_back(x);
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		int tot = 0;
		for(const auto &j: G[i])
			tot += G[j].size();
		if(tot > maxn)
		{
			maxn = tot;
			maxi = i;
		}
	}
	printf("%d %d", maxi, maxn);
	return 0;
}