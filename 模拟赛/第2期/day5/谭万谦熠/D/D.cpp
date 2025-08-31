#include <cstdio>
#include <set>
using namespace std;

set<int> G[3003];

int main()
{
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].insert(b);
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			for(int k = 1; k <= n; ++k)
				for(int l = 1; l <= n; ++l)
					if(i != j && j != k && k != l && l != i && G[i].find(j) != G[i].cend() && G[i].find(k) != G[i].cend() && G[j].find(l) != G[j].cend() && G[k].find(l) != G[k].cend())
						++ans;
	printf("%d", ans / 2);
	return 0;
}