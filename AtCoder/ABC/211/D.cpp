#include <cstdio>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<int> G[200003];
queue<int> q;
int dis[200003], f[200003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i = 0; i <= n; ++i)
		dis[i] = INF;
	dis[1] = 0;
	f[1] = 1;
	q.push(1);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(const auto &y: G[x])
		{
			if(dis[y] <= dis[x])
				continue;
			else if(dis[y] == dis[x] + 1)
				f[y] = (f[x] + f[y]) % static_cast<int>(1e9 + 7);
			else
			{
				f[y] = f[x];
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
	}
	printf("%d", f[n]);
	return 0;
}