#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

inline int ceil(const int &x, const int &y)
{ return x / y + !!(x % y); }

int main()
{
	int n, ans = INT_MAX;
	scanf("%d", &n);
	for(int i = 0; i < 3; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		ans = min(ans, ceil(n, a) * b);
	}
	printf("%d", ans);
	return 0;
}