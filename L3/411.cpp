#include <bits/stdc++.h>
using namespace std;

const int d[4][2]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
struct Edge
{
	int to, l;
	Edge(const int &x, const int &y)
	: to(x), l(y)
	{ }
};
vector<Edge> edges[40003];
vector<int> c[1003];
int m, a[103][103], dist[40003];

void calc()
{
	memset(dist, 255, sizeof(dist));
	int s = a[1][1] * m * m + 1;
	dist[s] = 0;
	c[0].push_back(s);
	for(int i = 0; ; ++i)
	{
		int f = 0, r = c[i].size() - 1;
		while(f <= r)
		{
			int x = c[i][f++];
			for(const auto &y: edges[x])
				if(!y.l && dist[y.to] == -1)
				{
					dist[y.to] = i;
					c[i].push_back(y.to);
					++r;
				}
		}
		for(const auto &j: c[i])
			for(const auto &y: edges[j])
				if(y.l && dist[y.to] == -1)
				{
					dist[y.to] = i + 1;
					c[i + 1].push_back(y.to);
				}
		if(c[i + 1].empty())
			break;
	}
	int ans = INT_MAX;
	if(dist[m * m] != -1)
		ans = min(ans, dist[m * m]);
	if(dist[2 * m * m] != -1)
		ans = min(ans, dist[2 * m * m]);
	if(ans == INT_MAX)
		ans = -1;
	printf("%d", ans);
}

int main()
{
	memset(a, 255, sizeof(a));
	int n;
	scanf("%d%d", &m, &n);
	while(n--)
	{
		int x, y, b;
		scanf("%d%d%d", &x, &y, &b);
		a[x][y] = b;
	}
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= m; ++j)
			for(int k = 0; k < 4; ++k)
			{
				int x = i + d[k][0], y = j + d[k][1];
				if(1 > x || x > m || 1 > y || y > m)
					continue;
				const int s = (i - 1) * m + j, t = (x - 1) * m + y;
				if(a[i][j] != -1)
					if(a[x][y] == a[i][j])
						edges[a[i][j] * m * m + s].push_back(Edge(a[i][j] * m * m + t, 0));
					else if(a[x][y] != -1)
						edges[a[i][j] * m * m + s].push_back(Edge(a[x][y] * m * m + t, 1));
					else
						edges[a[i][j] * m * m + s].push_back(Edge((a[i][j] + 2) * m * m + t, 1));
				else if(a[x][y] != -1)
				{
					edges[a[x][y] * m * m + s].push_back(Edge(a[x][y] * m * m + t, 0));
					edges[(1 - a[x][y]) * m * m + s].push_back(Edge(a[x][y] * m * m + t, 1));
				}
			}
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= m; ++j)
			if(a[i][j] == -1)
			{
				int s = (i - 1) * m + j;
				edges[2 * m * m + s].push_back(Edge(s, 1));
				edges[3 * m * m + s].push_back(Edge(m * m + s, 1));
			}
	calc();
	return 0;
}