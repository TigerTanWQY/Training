#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> G[103];
int ans = 0;

void dfs(const int &p, const int &d)
{
	ans = max(ans, d);
	for(const auto &x: G[p])
		dfs(x, d + 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int x, y; scanf("%d%d", &x, &y) != EOF; )
		G[x].push_back(y);
	dfs(1, 1);
	printf("%d", ans);
	return 0;
}