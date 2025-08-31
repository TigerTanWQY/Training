#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1003;
bool G[N][N], vis[N];
int a[N], b[N], f[N], n;

int func(const int &u)
{
	if(f[u] != -1)
		return f[u];
	f[u] = 0;
	for(int v = 1; v <= n; ++v)
		if(G[u][v])
			f[u] = max(f[u], func(v) + 1);
	return f[u];
}

int main()
{
	int m, ans = 0;
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int s, k = 0;
		scanf("%d", &s);
		for(int i = 0; i < s; ++i)
		{
			scanf("%d", &a[i]);
			vis[a[i]] = true;
		}
		for(int i = a[0]; i <= a[s - 1]; ++i)
			if(!vis[i])
				b[k++] = i;
		for(int i = 0; i < s; ++i)
			for(int j = 0; j < k; ++j)
				G[a[i]][b[j]] = true;
		memset(vis, false, sizeof(vis));
	}
	memset(f, 255, sizeof(f));
	for(int i = 1; i <= n; ++i)
		ans = max(ans, func(i));
	printf("%d", ans + 1);
	return 0;
}