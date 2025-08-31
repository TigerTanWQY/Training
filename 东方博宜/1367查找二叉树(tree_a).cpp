#include <cstdio>
#include <cstdlib>
using namespace std;

struct TreeNode
{ int v, l, r; }
a[103];
int x, ans = 0;

void midOrder(const int &p)
{
	if(a[p].l)
		midOrder(a[p].l);
	++ans;
	if(a[p].v == x)
	{
		printf("%d", ans);
		exit(0);
	}
	if(a[p].r)
		midOrder(a[p].r);
}

int main()
{
	int n;
	scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d%d", &a[i].v, &a[i].l, &a[i].r);
	midOrder(1);
	return 0;
}