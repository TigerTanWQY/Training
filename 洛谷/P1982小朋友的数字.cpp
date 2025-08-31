#include <cstdio>
#include <algorithm>
using namespace std;
using LL = long long;

int main()
{
	int n, p, a;
	scanf("%d%d%d", &n, &p, &a);
	bool flag = a > 0 && n > 1;
	LL maxx = a, tot = max(a, 0), ans = 2 * a;
	n -= 2;
	for(int c; n-- > 0; tot = max(tot, 0LL))
	{
		scanf("%d", &c);
		ans += max(maxx = max(maxx, tot += c), 0LL);
		if(flag)
			ans %= p;
		else if(ans > a)
			flag = true;
	}
	if(!flag)
		ans = a;
	printf("%lld", ans % p);
	return 0;
}