#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[1000003];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	for(int i = 1; i <= n; ++i)
		if(G[i].empty())
			++ans;
	printf("%d", ans);
	return 0;
}