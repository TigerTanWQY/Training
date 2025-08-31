#include <bits/stdc++.h>
using namespace std;

vector<int> edges[1003];
int d[1003];
bool b[1003];

void depth(const int &p)
{
	b[p] = true;
	for(const auto &x: edges[p])
		if(!b[x])
		{
			d[x] = d[p] + 1;
			depth(x);
		}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	for(int i = 1; i <= n; ++i)
	{
		memset(b, false, sizeof(b));
		memset(d, 0, sizeof(d));
		d[i] = 1;
		depth(i);
		int ans = 0;
		for(int j = 1; j <= n; ++j)
			ans = max(ans, d[j]);
		printf("%d ", ans);
	}
	return 0;
}