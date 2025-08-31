#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 40003;
int x[N], a[N], b[N], c[N], d[N], vis[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d", &x[i]);
		++vis[x[i]];
	}
	for(int t = 1, tot; 9 * t < n; ++t)
	{
		tot = 0;
		for(int D = 9 * t + 2; D <= n; ++D)
		{
			const int A = D - 9 * t - 1, B = A + 2 * t, C = D - t;
			tot += vis[A] * vis[B];
			c[C] += vis[D] * tot;
			d[D] += vis[C] * tot;
		}
		tot = 0;
		for(int A = n - 9 * t - 1; A; --A)
		{
			const int B = A + 2 * t, C = B + 6 * t + 1, D = A + 9 * t + 1;
			tot += vis[C] * vis[D];
			a[A] += vis[B] * tot;
			b[B] += vis[A] * tot;
		}
	}
	for(int i = 1; i <= m; ++i)
		printf("%d %d %d %d\n", a[x[i]], b[x[i]], c[x[i]], d[x[i]]);
	return 0;
}