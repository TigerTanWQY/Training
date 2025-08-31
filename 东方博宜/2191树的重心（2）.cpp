#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

const int N = 100003;
struct TreeNode
{ int from, to, next; }
a[2 * N];
int r[N], fa[N], pre[N], si[N], k = 0, cnt = 0;

inline void add(const int &u, const int &v)
{
	a[++k].from = u;
	a[k].to = v;
	a[k].next = pre[u];
	pre[u] = k;
}

int dfs(const int &x, const int &f)
{
	si[x] = 1;
	fa[x] = f;
	for(int i = pre[x]; i; i = a[i].next)
		if(a[i].to != f)
			si[x] += dfs(a[i].to, x);
	return si[x];
}

void solve(const int &x, const int &f)
{
	++cnt;
	for(int i = pre[x]; i; i = a[i].next)
		if(a[i].to != f)
			solve(a[i].to, x);
}

int main()
{
	int n, minn = INT_MAX, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; ++i)
	{
		r[i] = n - si[i];
		for(int j = pre[i]; j; j = a[j].next)
			if(fa[a[j].to] == i)
				r[i] = max(r[i], si[a[j].to]);
		minn = min(minn, r[i]);
	}
	for(int i = 1; i <= n; ++i)
		if(r[i] == minn) //r[i]ÊÇÖØÐÄ
			for(int j = pre[i]; j; j = a[j].next)
			{
				solve(a[j].to, i);
				ans = max(ans, cnt);
				cnt = 0;
			}
	printf("%d", ans);
	return 0;
}