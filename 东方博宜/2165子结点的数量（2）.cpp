#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[103];

int main()
{
	int n;
	scanf("%d", &n);
	G[1].push_back(0);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i = 1; i <= n; ++i)
		printf("%llu ", G[i].size() - 1);
	return 0;
}