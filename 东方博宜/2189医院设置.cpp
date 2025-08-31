#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode
{ int v, fa, l, r; }
a[103];
bool vis[103];

int calc(const int &x, const int &d)
{
	if(!x || vis[x])
		return 0;
	vis[x] = true;
	return calc(a[x].l, d + 1) + calc(a[x].r, d + 1) + calc(a[x].fa, d + 1) + a[x].v * d;
}

int main()
{
	int n, ans = INT_MAX;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d", &a[i].v, &a[i].l, &a[i].r);
		a[a[i].l].fa = a[a[i].r].fa = i;
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			vis[j] = false;
		ans = min(ans, calc(i, 0));
	}
	printf("%d", ans);
	return 0;
}