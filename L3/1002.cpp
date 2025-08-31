#include <bits/stdc++.h>
using namespace std;

vector<int> edges[100003];
int f[100003][20], d[100003];

void dfs(const int &p)
{
	for(const auto &x: edges[p])
	{
		d[x] = d[p] + 1;
		dfs(x);
	}
}

int main()
{
	int n, m;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		f[y][0] = x;
	}
	for(int j = 1; j <= 17; ++j)
		for(int i = 1; i <= n; ++i)
			f[i][j] = f[f[i][j - 1]][j - 1];
	d[1] = 1;
	dfs(1);
	scanf("%d", &m);
	while(m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if(d[u] < d[v])
			swap(u, v);
		int c = d[u] - d[v];
		for(int i = 0; c; c /= 2, ++i)
			if(c & 1)
				u = f[u][i];
		if(u == v)
		{
			printf("%d\n", u);
			continue;
		}
		for(int j = 17; j >= 0; --j)
			if(f[u][j] != f[v][j])
			{
				u = f[u][j];
				v = f[v][j];
			}
		printf("%d\n", f[u][0]);
	}
	return 0;
}