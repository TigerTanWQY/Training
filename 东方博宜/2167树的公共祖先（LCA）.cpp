#include <cstdio>
#include <algorithm>
using namespace std;

int fa[103], b[103], c[103], l1 = 0, l2 = 0;

int main()
{
	int n, u, v, ans = 0;
	scanf("%d%d%d", &n, &u, &v);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		fa[x] = y;
	}
	for(; u != 1; u = fa[u])
		b[++l1] = u;
	b[++l1] = 1;
	for(int i = 1, j = l1; i < j; ++i, --j)
		swap(b[i], b[j]);
	for(; v != 1; v = fa[v])
		c[++l2] = v;
	c[++l2] = 1;
	for(int i = 1, j = l2; i < j; ++i, --j)
		swap(c[i], c[j]);
	for(int i = 1; i <= l1 && i <= l2; ++i)
		if(b[i] == c[i])
			ans = b[i];
		else
			break;
	printf("%d", ans);
	return 0;
}