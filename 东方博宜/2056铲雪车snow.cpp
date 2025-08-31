#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int x, y;
	scanf("%d%d", &x, &y);
	double tot = 0;
	for(long long sx, sy, ex, ey; scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey) != EOF; tot += sqrt((sx - ex) * (sx - ex) + (sy - ey) * (sy - ey)));
	double ans = tot / 10000;
	long long h = static_cast<int>(ans), f = static_cast<int>((ans - h) * 60 + 0.5);
	printf("%lld:%02lld", h, f);
	return 0;
}