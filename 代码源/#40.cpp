#include <cstdio>
using namespace std;

inline long long fac(const int &x)
{
	long long ret = 1;
	for(int i = 2; i <= x; ++i)
		ret *= i;
	return ret;
}

int main()
{
	while(true)
	{
		int n;
		scanf("%d", &n);
		if(n == 0)
			break;
		printf("%lld ", fac(n));
	}
	return 0;
}