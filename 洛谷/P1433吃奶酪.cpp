#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

pair<double, double> c[18];
double a[18][18], f[18][32771];

double dist(const int &i, const int &j)
{ return sqrt((c[i].first - c[j].first) * (c[i].first - c[j].first) + (c[i].second - c[j].second) * (c[i].second - c[j].second)); }

int main()
{
	memset(f, 127, sizeof(f));
	int n;
	double ans = f[0][0];
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lf%lf", &c[i].first, &c[i].second);
	for(int i = 0; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			a[i][j] = a[j][i] = dist(i, j);
	for(int i = 1; i <= n; ++i)
		f[i][1 << (i - 1)] = a[0][i];
	for(int k = 1; k < (1 << n); ++k)
		for(int i = 1; i <= n; ++i)
		{
			if((k & (1 << (i - 1))) == 0)
				continue;
			for(int j = 1; j <= n; ++j)
			{
				if(i == j)
					continue;
				if((k & (1 << (j - 1))) == 0)
					continue;
				f[i][k] = min(f[i][k], f[j][k - (1 << (i - 1))] + a[i][j]);
			}
		}
	for(int i = 1; i <= n; ++i)
		ans = min(ans, f[i][(1 << n) - 1]);
	printf("%.2lf", ans);
	return 0;
}