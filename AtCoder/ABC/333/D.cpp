#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 300003;
vector<int> G[N];
int d[N], dist[N];

void bfs()
{
	queue<int> q;
	q.push(1);
	dist[1] = 1;
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		for(const auto &p: G[f])
			if(dist[p] == 0x3f3f3f3f)
				dist[p] = min(dist[p], dist[f] + 1);
	}
}

int main()
{
	int n, ans = 0x3f3f3f3f;
	scanf("%d", &n);
	for(int _ = 1; _ < n; ++_)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		++d[u];
		++d[v];
	}
	memset(dist, 0x3f, sizeof(dist));
	bfs();
	for(int i = 1; i <= n; ++i)
		if(d[i] == 1)
			ans = min(ans, dist[i]);
	printf("%d", ans);
	return 0;
}
