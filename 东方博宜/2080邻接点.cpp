#include <cstdio>
#include <set>
using namespace std;

set<int> G[1000003];

int main()
{
	int n, e;
	scanf("%d%d", &n, &e);
	while(e--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].insert(y);
	}
	for(int i = 1; i <= n; ++i)
		if(G[i].size())
		{
			printf("%d\n", i);
			for(const auto &x: G[i])
				printf("%d ", x);
			printf("\n");
		}
	return 0;
}