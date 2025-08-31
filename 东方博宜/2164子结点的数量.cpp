#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[103];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
	}
	for(int i = 1; i <= n; ++i)
		printf("%llu ", G[i].size());
	return 0;
}