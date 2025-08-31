#include <bits/stdc++.h>
using namespace std;

struct Edge
{
	int to, v;
	Edge(const int &x, const int &y)
	: to(x), v(y)
	{ }
};
vector<Edge> edges[10003];
int f[10003];

int main()
{
	memset(f, 127, sizeof(f));
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		edges[y].push_back(Edge(x, z));
	}
	f[1] = 0;
	for(int i = 2; i <= n; ++i)
		for(const auto &y: edges[i])
			f[i] = min(f[i], f[y.to] + y.v); //×´Ì¬×ªÒÆ·½³Ì
	printf("%d", f[n]);
	return 0;
}