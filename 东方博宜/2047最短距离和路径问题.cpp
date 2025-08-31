#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
bool f[1002];
int a[1002][1002], d[1002], r[1002], n;

void Dijkstra(const int &s, const int &t)
{
	for(int i = 1; i <= n; ++i)
		d[i] = INF;
	d[s] = 0;
	for(int _ = 0; _ < n; ++_)
	{
		int x = -1;
		for(int i = 1; i <= n; ++i)
			if(!f[i] && (x == -1 || d[i] < d[x]))
				x = i;
		if(x == t || x == -1)
			break;
		f[x] = true;
		for(int i = 1; i <= n; ++i)
			if(!f[i] && a[x][i] && d[x] + a[x][i] < d[i])
			{
				d[i] = d[x] + a[x][i];
				r[i] = x;
			}
	}
}

void print(const int &k)
{
	if(r[k])
		print(r[k]);
	printf("%d ", k);
}

int main()
{
	int m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	while(m--)
	{
		int x, y, len;
		scanf("%d%d%d", &x, &y, &len);
		if(!a[x][y] || len < a[x][y])
			a[x][y] = a[y][x] = len;
	}
	Dijkstra(s, t);
	if(d[t] != INF)
	{
		printf("%d\n", d[t]);
		print(t);
	}
	else
		printf("can't arrive");
	return 0;
}