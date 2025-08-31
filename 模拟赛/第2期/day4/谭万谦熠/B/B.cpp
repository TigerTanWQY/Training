#include <cstdio>
using namespace std;
using LL = long long;

const int N = 100003;
struct Op
{
	int l, r, d;
	LL s;
} c[N];
LL a[N], s[N];

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	for(int i = 1; i <= m; ++i)
		scanf("%d%d%d", &c[i].l, &c[i].r, &c[i].d);
	while(k--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		++c[x].s;
		--c[y + 1].s;
	}
	for(int i = 1; i <= m; ++i)
	{
		c[i].s += c[i - 1].s;
		s[c[i].l] += c[i].d * c[i].s;
		s[c[i].r + 1] -= c[i].d * c[i].s;
	}
	for(int i = 1; i <= n; ++i)
	{
		s[i] += s[i - 1];
		printf("%lld ", a[i] + s[i]);
	}
	return 0;
}