#include <bits/stdc++.h>
using namespace std;

vector<int> edges[100003];
int d[100003]{0, 1}, q[100003], f = 1, r = 0;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
	}
	q[++r] = 1;
	while(f <= r)
	{
		int x = q[f++];
		for(const auto &y: edges[x])
		{
			d[y] = d[x] + 1;
			q[++r] = y;
		}
	}
	for(int i = 1; i <= n; ++i)
		printf("%d ", d[i]);
	return 0;
}