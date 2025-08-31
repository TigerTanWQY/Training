#include <cstdio>
using namespace std;

inline int get1(int n)
{
	int ret = 0;
	for(; n; n >>= 1)
		if(n % 2)
			ret++;
	return ret;
}

int main()
{
	int n;
	long long cnt = 0;
	scanf("%d", &n);
	for(int i = 1, day = 1; i <= n && day <= n; ++i)
		for(int j = 1; j <= get1(i) && day <= n; ++day, ++j)
			cnt += i;
	printf("%lld", cnt);
	return 0;
}