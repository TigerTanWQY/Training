#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<int> s;
vector<int> G[1003];
int fa[1003];

int main()
{
	int n, r = 0, maxn = 0, maxi = 0;
	scanf("%d", &n);
	for(int x, y; scanf("%d%d", &x, &y) != EOF; )
	{
		s.insert(x);
		s.insert(y);
		G[x].push_back(y);
		fa[y] = x;
	}
	for(const auto &i: s)
		if(!fa[i])
		{
			r = i;
			break;
		}
	printf("%d\n", r);
	for(const auto &i: s)
		if(G[i].size() >= maxn)
		{
			maxn = G[i].size();
			maxi = i;
		}
	printf("%d\n", maxi);
	sort(G[maxi].begin(), G[maxi].end());
	for(const auto &p: G[maxi])
		printf("%d ", p);
	return 0;
}