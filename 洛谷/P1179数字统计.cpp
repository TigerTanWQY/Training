#include <cstdio>
using namespace std;

inline int cnt(int x)
{
	int ret = 0;
	for(; x; x /= 10)
		if(x % 10 == 2)
			++ret;
	return ret;
}

int main()
{
	int L, R, ans = 0;
	scanf("%d%d", &L, &R);
	for(int i = L; i <= R; ++i)
		ans += cnt(i);
	printf("%d", ans);
	return 0;
}