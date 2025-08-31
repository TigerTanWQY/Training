#include <cstdio>
#include <cmath>
using namespace std;

inline long long split(const long long &x)
{
	long long ret = 0;
	for(long long i = 1; i <= sqrt(x); ++i)
		if(x % i == 0)
		{
			if(i * i != x)
				++ret;
			++ret;
		}
	return ret;
}

int main()
{
	long long n;
	scanf("%lld", &n);
	if(split(sqrt(n)) == 2)
		printf("Yes");
	else
		printf("No");
	return 0;
}