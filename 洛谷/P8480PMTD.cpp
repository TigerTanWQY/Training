#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, maxn = 0, minn = INT_MAX;
	scanf("%d%d", &n, &m);
	while(n--)
	{
		int v;
		scanf("%d", &v);
		maxn = max(maxn, v);
		minn = min(minn, v);
	}
	if(maxn < 2)
	{
		maxn += 2;
		--m;
	}
	printf("%lld", ((1LL * maxn) << m) - minn);
	return 0;
}