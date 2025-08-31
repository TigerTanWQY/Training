#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

pair<int, int> a[503];
set<pair<int, int>> s;

inline int gcd(int x, int y)
{
	while(y)
	{
		int tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].first, &a[i].second);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
		{
			int tx = a[j].first - a[i].first, ty = a[j].second - a[i].second, g = gcd(abs(tx), abs(ty));
			s.insert(make_pair(tx / g, ty / g));
		}
	printf("%llu", 2 * s.size());
	return 0;
}