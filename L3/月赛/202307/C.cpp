#include <cstdio>
#include <cmath>
using namespace std;

inline long long split(const long long &x)
{
	long long ret = 0;
	for(int a = 1, b = x; a <= b; ++a, b = x / a)
		if(x % a == 0)
			if(a == b)
				++ret;
			else
				ret += 2;
	return ret;
}

int main()
{
	long long n;
	scanf("%lld", &n);
	if(split(split(n)) == 2)
		printf("T");
	else
		printf("F");
	return 0;
}