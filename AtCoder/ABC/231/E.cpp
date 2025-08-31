#include <cstdio>
#include <map>
using namespace std;
using LL = long long;

map<LL, LL> mp;
int n;
LL a[63];

inline LL ceil(const LL &x, const LL &y) //为了避免精度误差
{ return x / y + !!(x % y); }

LL dfs(const LL &x, const int &stt)
{
	if(mp.find(x) != mp.end())
		return mp[x];
	if(stt == n - 1)
		return x / a[n - 1];
	if(x == 0)
		return 0;
	LL pst = a[stt], nxt = a[stt + 1], r = x % nxt / pst, ans = dfs(x / nxt * nxt, stt + 1) + r;
	if(r)
		ans = min(ans, dfs(ceil(x, nxt) * nxt, stt + 1) + nxt / pst - r);
	return mp[x] = ans;
}

int main()
{
	LL x;
	scanf("%d%lld", &n, &x);
	for(int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	printf("%lld", dfs(x, 0));
	return 0;
}