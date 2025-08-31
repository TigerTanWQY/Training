#include <bits/stdc++.h>
using namespace std;

struct Node
{
	double x, y;
	bool operator<(const Node &A) const
	{ return x < A.x; }
} a[200003], c[200003];

double solve(const int &l, const int &r)
{
	if(l == r)
		return 1e20;
	int n = (l + r) / 2, cnt = 0;
	double d = min(solve(l, n), solve(n + 1, r));
	for(int i = l; i <= r; ++i)
		if(abs(a[i].x - a[n].x) < d)
		{
			c[++cnt].x = a[i].y;
			c[cnt].y = a[i].x;
		}
	sort(c + 1, c + cnt + 1);
	for(int i = 1; i <= cnt; ++i)
		for(int j = i + 1; j <= cnt && c[j].x - c[i].x < d; ++j)
			d = min(d, sqrt((c[j].x - c[i].x) * (c[j].x - c[i].x) + (c[j].y - c[i].y) * (c[j].y - c[i].y)));
	return d;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lf%lf", &a[i].x, &a[i].y);
	sort(a + 1, a + n + 1);
	printf("%.8f", solve(1, n));
	return 0;
}