#include <cstdio>
#include <vector>
using namespace std;

vector<int> edges[20003];
bool vis[20003];
int a[20003], b[20003], cnt;

void dfs(const int &p)
{
	vis[p] = true;
	++cnt;
	for(const auto &y: edges[p])
		if(!vis[y])
			dfs(y);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &b[i]);
		while(m--)
		{
			int c, d;
			scanf("%d%d", &c, &d);
			edges[c].push_back(d);
			edges[d].push_back(c);
		}
		dfs(1);
		if(cnt == n)
			printf("Yes\n");
		else
			printf("No\n");
		for(int i = 1; i <= n; ++i)
		{
			edges[i].clear();
			vis[i] = false;
		}
		cnt = 0;
	}
	return 0;
}