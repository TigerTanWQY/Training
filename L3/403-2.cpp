#include <bits/stdc++.h>
using namespace std;

vector<int> edges[1003];
bool b[1003];
int q[1003], ans = 0;

void bfs(const int &p)
{
	int f = 1, r = 0;
	q[++r] = p;
	b[p] = true;
	while(f <= r)
	{
		++ans;
		int x = q[f++];
		for(const auto &y: edges[x])
			if(!b[y])
			{
				b[y] = true;
				q[++r] = y;
			}
	}
	memset(b, false, sizeof(b));
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
	}
	for(int i = 1; i <= n; ++i)
		bfs(i);
	printf("%d", ans);
	return 0;
}