#include <cstdio>
#include <algorithm>
using namespace std;

int v[100003];

int main()
{
	int n, d, minn = 0x3f3f3f3f;
	scanf("%d%d", &n, &d);
	for(int i = 1; i < n; ++i)
		scanf("%d", &v[i]);
	long long ans = 0, tot = 0;
	for(int i = 1, a; i < n; ++i)
	{
		scanf("%d", &a);
		tot += v[i];
		minn = min(minn, a);
		if(tot > 0)
		{
			ans += (tot + d - 1) / d * minn;
			tot -= (tot + d - 1) / d * d;
		}
	}
	printf("%lld", ans);
	return 0;
}