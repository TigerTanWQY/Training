#include <bits/stdc++.h>
using namespace std;

struct Info
{
	int d1, d2;
	bool operator<(const Info& a) const
	{ return d1 < a.d1; }
} a[100003];
int f[100013];
int X1, Y1, X2, Y2;

int main()
{
	scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[i].d1 = (x - X1) * (x - X1) + (y - Y1) * (y - Y1);
		a[i].d2 = (x - X2) * (x - X2) + (y - Y2) * (y - Y2);
	}
	sort(a + 1, a + n + 1);
	for(int i = n; i >= 1; --i)
		f[i] = max(f[i + 1], a[i].d2);
	int ans = 16000001;
	for(int i = 0; i <= n; ++i)
		ans = min(ans, a[i].d1 + f[i + 1]);
	printf("%d", ans);
	return 0;
}