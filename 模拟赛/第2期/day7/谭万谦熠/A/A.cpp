#include <cstdio>
#include <map>
using namespace std;

map<int, int> cnt;

inline int solve(int x)
{
	int ret = 0;
	for(; x; x >>= 1)
		if(x & 1)
			++ret;
	return ret;
}

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		++cnt[solve(x)];
	}
	for(const auto &p: cnt)
		ans += p.second * (p.second - 1) / 2; // 线性化+数学化
	printf("%d", ans);
	return 0;
}