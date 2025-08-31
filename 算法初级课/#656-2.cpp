#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
set<pair<int, int>> q;
vector<pair<int, int>> G[5003];
int f[3][5003], n, m;

void Dijkstra(const int &s, const int &id)
{
	for(int i = 1; i <= n; ++i)
		f[id][i] = INF;
	f[id][s] = 0;
	q.clear();
	for(int i = 1; i <= n; ++i)
		q.insert(make_pair(f[id][i], i));
	while(!q.empty())
	{
		int x = q.cbegin()->second;
		q.erase(q.cbegin());
		if(f[id][x] >= INF)
			break;
		for(const auto &p: G[x])
			if(f[id][x] + p.second < f[id][p.first])
			{
				q.erase(make_pair(f[id][p.first], p.first));
				f[id][p.first] = f[id][x] + p.second;
				q.insert(make_pair(f[id]
									[p.first], p.first));
			}
	}
}

int main()
{
	int a, b, c, ans = 0x7fffffff;
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		G[x].push_back(make_pair(y, z));
		G[y].push_back(make_pair(x, z));
	}
	scanf("%d%d%d", &a, &b, &c);
	Dijkstra(a, 0);
	Dijkstra(b, 1);
	Dijkstra(c, 2);
	for(int i = 1; i <= n; ++i)
		if(f[0][i] + f[1][i] + f[2][i] < ans)
			ans = f[0][i] + f[1][i] + f[2][i];
	printf("%d", ans);
	return 0;
}