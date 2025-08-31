#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3003;
vector<int> g[N];
bool used[N];
LL x[N], y[N], r[N];
int t;

bool dfs(const int &v)
{
	used[v] = true;
	if(v == t)
		return true;
	for(const auto &u: g[v])
	{
		if(used[u])
			continue;
		if(dfs(u))
			return true;
	}
	return false;
}

int main()
{
	int n, s;
	LL sx, sy, tx, ty;
	scanf("%d%lld%lld%lld%lld", &n, &sx, &sy, &tx, &ty);
	for(int i = 1; i <= n; ++i)
		scanf("%lld%lld%lld", &x[i], &y[i], &r[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
		{
			LL d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			if(d > (r[i] + r[j]) * (r[i] + r[j]) || d < (r[i] - r[j]) * (r[i] - r[j]))
				continue;
			g[i].push_back(j);
			g[j].push_back(i);
		}
	for(int i = 1; i <= n; ++i)
	{
		if((x[i] - sx) * (x[i] - sx) + (y[i] - sy) * (y[i] - sy) == r[i] * r[i])
			s = i;
		if((x[i] - tx) * (x[i] - tx) + (y[i] - ty) * (y[i] - ty) == r[i] * r[i])
			t = i;
	}
	if(dfs(s))
		printf("Yes");
	else
		printf("No");
	return 0;
}