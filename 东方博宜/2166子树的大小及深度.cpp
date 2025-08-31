#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[103];
int c[103], d[103];

void dfs(const int &p)
{
	c[p] = 1;
	for(const auto &x: G[p])
		if(!d[x])
		{
			d[x] = d[p] + 1;
			dfs(x);
			c[p] += c[x];
		}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	d[1] = 1;
	dfs(1);
	for(int i = 1; i <= n; ++i)
		printf("%d %d\n", c[i], d[i]);
	return 0;
}