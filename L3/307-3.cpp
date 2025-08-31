#include <bits/stdc++.h>
using namespace std;

vector<int> edges[1000003];
int pre[1000003], q[1000003], f = 1, r = 0;

void bfs(const int &p)
{
	q[++r] = p;
	while(f <= r)
	{
		int x = q[f++];
		for(const auto &y: edges[x])
			if(pre[x] != y)
			{
				pre[y] = x;
				q[++r] = y;
			}
	}
}

int main()
{
	int n, u, v;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	scanf("%d%d", &u, &v);
	bfs(v);
	for(; u != v; u = pre[u])
		printf("%d ", u);
	printf("%d", v);
	return 0;
}