#include <bits/stdc++.h>
using namespace std;

vector<int> e[200003];
int dis[200003], q[200003], h = 1, t = 1;

int main()
{
	int n, m, Q;
	scanf("%d%d%d", &n, &m, &Q);
	while(m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		e[2 * u - 1].push_back(2 * v - 2);
		e[2 * u - 2].push_back(2 * v - 1);
		e[2 * v - 1].push_back(2 * u - 2);
		e[2 * v - 2].push_back(2 * u - 1);
	}
	for(int i = 1; i < 2 * n; ++i)
		dis[i] = INT_MAX;
	while(h <= t)
	{
		int u = q[h++];
		for(const auto &v: e[u])
			if(dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				q[++t] = v;
			}
	}
	while(Q--)
	{
		int a, L;
		scanf("%d%d", &a, &L);
		if(e[0].empty())
			printf("No\n");
		else
		{
			int u = 2 * a - 2 + L % 2;
			if(L >= dis[u])
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}