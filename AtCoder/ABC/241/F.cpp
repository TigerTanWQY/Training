#include <cstdio>
#include <map>
#include <set>
#include <queue>
using namespace std;

map<pair<int, int>, bool> b;
set<pair<int, int>> r, c;

void bfs(const int &sx, const int &sy, const int &gx, const int &gy)
{
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(sx, sy), 0));
	while(!q.empty())
	{
		auto f = q.front();
		q.pop();
		int x = f.first.first, y = f.first.second, u = f.second;
		if(x == gx && y == gy)
		{
			printf("%d", u);
			return;
		}
		if(b[f.first])
			continue;
		b[f.first] = true;
		auto it = r.lower_bound(make_pair(x, y));
		if(it == r.cend())
			continue;
		int tx = it->first, ty = it->second;
		if(x == tx && y != ty - 1)
			q.push(make_pair(make_pair(tx, ty - 1), u + 1));
		--it;
		tx = it->first;
		ty = it->second;
		if(x == tx && y != ty + 1)
			q.push(make_pair(make_pair(tx, ty + 1), u + 1));
		it = c.lower_bound(make_pair(y, x));
		if(it == c.cend())
			continue;
		tx = it->second, ty = it->first;
		if(y == ty && x != tx - 1)
			q.push(make_pair(make_pair(tx - 1, ty), f.second + 1));
		--it;
		tx = it->second;
		ty = it->first;
		if(y == ty && x != tx + 1)
			q.push(make_pair(make_pair(tx + 1, ty), f.second + 1));
	}
	printf("-1");
}

int main()
{
	int n, sx, sy, gx, gy;
	scanf("%*d%*d%d%d%d%d%d", &n, &sx, &sy, &gx, &gy);
	while(n--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		r.insert(make_pair(x, y));
		c.insert(make_pair(y, x));
	}
	bfs(sx, sy, gx, gy);
	return 0;
}