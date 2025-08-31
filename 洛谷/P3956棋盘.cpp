#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

const int d[4][2]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
vector<pair<int, bool>> G[40003];
vector<int> c[1003];
int a[103][103], dist[40003];

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= m; ++j)
			a[i][j] = -1;
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
				const int x = i + d[k][0];
				const int y = j + d[k][1];
				if(1 > x || x > m || 1 > y || y > m)
					continue;
				const int s = (i - 1) * m + j;
				const int t = (x - 1) * m + y;
				if(a[i][j] != -1)
					if(a[x][y] == a[i][j])
						G[a[i][j] * m * m + s].push_back(make_pair(a[x][y] * m * m + t, false));
					else if(a[x][y] != -1)
						G[a[i][j] * m * m + s].push_back(make_pair(a[x][y] * m * m + t, true));
					else
						G[a[i][j] * m * m + s].push_back(make_pair((a[i][j] + 2) * m * m + t, true));
				else if(a[x][y] != -1)
				{
					G[a[x][y] * m * m + s].push_back(make_pair(a[x][y] * m * m + t, false));
					G[(1 - a[x][y]) * m * m + s].push_back(make_pair(a[x][y] * m * m + t, true));
				}
			}
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= m; ++j)
			if(a[i][j] == -1)
			{
				const int s = (i - 1) * m + j;
				G[2 * m * m + s].push_back(make_pair(s, true));
				G[3 * m * m + s].push_back(make_pair(m * m + s, true));
			}
	for(int i = 1; i <= 4 * m * m; ++i)
		dist[i] = -1;
	const int s = a[1][1] * m * m + 1;
	dist[s] = 0;
	c[0].push_back(s);
	for(int i = 0; ; ++i)
	{
		int f = 0, r = c[i].size() - 1;
		while(f <= r)
		{
			int x = c[i][f++];
			for(const auto &y: G[x])
				if(!y.second && dist[y.first] == -1)
				{
					dist[y.first] = i;
					c[i].push_back(y.first);
					++r;
				}
		}
		for(const auto &j: c[i])
			for(const auto &y: G[j])
				if(y.second && dist[y.first] == -1)
				{
					dist[y.first] = i + 1;
					c[i + 1].push_back(y.first);
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
		printf("-1");
	else
		printf("%d", ans);
	return 0;
}