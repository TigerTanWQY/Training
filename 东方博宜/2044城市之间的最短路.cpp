#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
bool f[53];
int G[53][53], d[53], n;

void Dijkstra(const int &s, const int &t)
{
	for(int i = 1; i <= n; ++i)
		d[i] = INF;
	d[s] = 0;
	for(int _ = 0; _ < n; ++_)
	{
		int x = -1;
		for(int j = 1; j <= n; ++j)
			if(!f[j] && (x == -1 || d[j] < d[x]))
				x = j;
		if(x == t || x == -1)
			break;
		f[x] = true;
		for(int j = 1; j <= n; ++j)
			if(!f[j] && G[x][j] && d[x] + G[x][j] < d[j])
				d[j] = d[x] + G[x][j];
	}
}

int main()
{
	int m, s, t;
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int a, b, l;
		scanf("%d%d%d", &a, &b, &l);
		G[a][b] = G[b][a] = l;
	}
	scanf("%d%d", &s, &t);
	Dijkstra(s, t);
	if(d[t] != INF)
		printf("%d", d[t]);
	else
		printf("No path");
	return 0;
}