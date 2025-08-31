#include <cstdio>
#include <map>
using namespace std;
using LL = long long;

const int N = 100003;
map<int, int> mp;
LL a[N], qzh[N], hzh[N];

int main() {
	int n;
	LL tot = 0, ans = 0;
	scanf("%d", &n);
	if(n < 3)
	{
		putchar('0');
		return 0;
	}
	for(int i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
		tot += a[i];
		qzh[i] = qzh[i - 1] + a[i];
	}
	for(int i = n; i >= 1; --i)
	{
		hzh[i] = hzh[i + 1] + a[i];
		++mp[hzh[i]];
	}
	--mp[hzh[1]];
	for(int i = 1; i < n - 1; ++i)
	{
		--mp[hzh[i + 1]];
		if(qzh[i] * 3 == tot)
			ans += mp[qzh[i]];
	}
	printf("%lld", ans);
	return 0;
}