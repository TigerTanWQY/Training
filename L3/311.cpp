#include <bits/stdc++.h>
using namespace std;

vector<int> edges[1003];
int a[1003], c[1003], cnt = 0, f[1003];
bool b[1003];

void dfs(const int &p, const int &l)
{
	b[p] = true;
	if(++c[a[p]] == 1)
		++cnt;
	if(p > l)
		++f[cnt];
	for(const auto &x: edges[p])
		if(!b[x])
			dfs(x, l);
	if(--c[a[p]] == 0)
		--cnt;
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
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
	{
		cnt = 0;
		dfs(i, i);
		memset(b, false, sizeof(b));
		memset(c, 0, sizeof(c));
	}
	for(int i = 1; i <= n; ++i)
		printf("%d ", f[i]);
	return 0;
}