#include <cstdio>
using namespace std;

const int N = 100003;
struct TreeNode
{ int from, to, next; }
a[2 * N];
int fa[N], dep[N], pre[N], k = 0;

inline void add(const int &u, const int &v)
{
	a[++k].from = u;
	a[k].to = v;
	a[k].next = pre[u];
	pre[u] = k;
}

void dfs(const int &x, const int &f)
{
	fa[x] = f;
	dep[x] = dep[f] + 1;
	for(int i = pre[x]; i; i = a[i].next)
		if(a[i].to != f)
			dfs(a[i].to, x);
}

int main()
{
	int n, x = 1;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
	for(int i = 2; i <= n; ++i)
		if(dep[i] > dep[x])
			x = i;
	dfs(x, 0);
	x = 1;
	for(int i = 2; i <= n; ++i)
		if(dep[i] > dep[x])
			x = i;
	int d = dep[x];
	if(d % 2)
	{
		for(int i = 1; i <= d / 2; ++i)
			x = fa[x];
		printf("%d", x);
	}
	else
	{
		for(int i = 1; i < d / 2; ++i)
			x = fa[x];
		if(x < fa[x])
			printf("%d %d", x, fa[x]);
		else
			printf("%d %d", fa[x], x);
	}
	return 0;
}