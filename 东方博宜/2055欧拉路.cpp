#include <cstdio>
using namespace std;

bool a[23][23];
int d[23], r[43], n, k = 0;

void dfs(const int &p)
{
	for(int i = 1; i <= n; ++i)
		if(a[p][i])
		{
			a[p][i] = a[i][p] = false;
			dfs(i);
		}
	r[++k] = p;
}

int main()
{
	int e, s = 1;
	scanf("%d%d", &n, &e);
	while(e--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = true;
		a[y][x] = true;
		++d[x];
		++d[y];
	}
	for(int i = n; i; --i)
		if(d[i] % 2)
		{
			s = i;
			break;
		}
	dfs(s);
	for(int i = k; i; --i)
		printf("%d ", r[i]);
	return 0;
}