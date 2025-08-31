#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[23];
int fa[23], d[23];

void dfs(const int &p)
{
	for(const auto &x: G[p])
		if(x != fa[p])
		{
			fa[x] = p;
			d[x] = d[p] + 1;
			dfs(x);
		}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int x, y; scanf("%d%d", &x, &y) != EOF; )
	{
		G[x].push_back(y);
		G[y].push_back(x);
	}
	d[1] = 1;
	dfs(1);
	for(int i = 1; i < n; ++i)
		printf("%d %d %d\n", i + 1, fa[i + 1], d[i + 1]);
	return 0;
}