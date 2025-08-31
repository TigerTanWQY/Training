#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

set<pair<int, int>> s;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		s.insert(make_pair(x, y));
	}
	printf("%llu\n", s.size());
	for(const auto &p: s)
		printf("%d %d\n", p.first, p.second);
	return 0;
}