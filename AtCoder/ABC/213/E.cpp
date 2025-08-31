#include <cstdio>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;

char s[503][503];
int dis[503][503], h, w;

int main()
{
	scanf("%d%d", &h, &w);
	for(int i = 1; i <= h; ++i)
	{
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= w; ++j)
			dis[i][j] = 1e9;
	}
	dis[1][1] = 0;
	deque<pair<int, int>> q;
	q.push_back(make_pair(1, 1));
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop_front();
		for(int tx = max(x - 2, 1); tx <= x + 2 && tx <= h; ++tx)
			for(int ty = max(y - 2, 1); ty <= y + 2 && ty <= w; ++ty)
			{
				int d = abs(tx - x) + abs(ty - y);
				if(d == 4)
					continue;
				bool c = d > 1 || s[tx][ty] == '#';
				if(dis[tx][ty] > dis[x][y] + c)
				{
					dis[tx][ty] = dis[x][y] + c;
					if(c)
						q.push_back(make_pair(tx, ty));
					else
						q.push_front(make_pair(tx, ty));
				}
			}
	}
	printf("%d", dis[h][w]);
	return 0;
}