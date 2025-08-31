#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
bool f[53];
int a[53][53], d[53], n;

void Dijkstra(const int &s)
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
		if(x == -1)
			break;
		f[x] = true;
		for(int j = 1; j <= n; ++j)
			if(!f[j] && a[x][j] && d[x] + a[x][j] < d[j])
				d[j] = d[x] + a[x][j];
	}
}

int main()
{
	int s;
	scanf("%d%d", &n, &s);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			scanf("%d", &a[i][j]);
			if(!a[i][j])
				a[i][j] = INF;
		}
	Dijkstra(s);
	for(int i = 1; i <= n; ++i)
		if(i != s)
			if(d[i] != INF)
				printf("%d ", d[i]);
			else
				printf("-1 ");
	return 0;
}