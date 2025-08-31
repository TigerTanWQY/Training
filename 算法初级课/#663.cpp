#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
set<pair<int, int>> q;
vector<pair<int, int>> G[2][10003];
int f[2][10003], n, m;

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
		for(const auto &p: G[id][x])
			if(f[id][x] + p.second < f[id][p.first])
			{
				q.erase(make_pair(f[id][p.first], p.first));
				f[id][p.first] = f[id][x] + p.second;
				q.insert(make_pair(f[id][p.first], p.first));
			}
	}
}

int main()
{
	int k, ans = 0;
	scanf("%d%d%d", &n, &m, &k);
	while(m--)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		G[0][x].push_back(make_pair(y, z));
		G[1][y].push_back(make_pair(x, z));
	}
	Dijkstra(k, 0);
	Dijkstra(k, 1);
	for(int i = 1; i <= n; ++i)
		if(f[0][i] + f[1][i] > ans)
			ans = f[0][i] + f[1][i];
	printf("%d", ans);
	return 0;
}