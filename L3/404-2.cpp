#include <bits/stdc++.h>
using namespace std;

vector<int> edges[20003];
bool b[20003];
int q[20003];

void bfs(const int &p)
{
	int f = 1, r = 0;
	q[++r] = p;
	b[p] = true;
	while(f <= r)
	{
		int x = q[f++];
		for(const auto &y: edges[x])
			if(!b[y])
			{
				b[y] = true;
				q[++r] = y;
			}
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(!b[i])
		{
			++ans;
			bfs(i);
		}
	printf("%d", ans);
	return 0;
}