#include <cstdio>
using namespace std;

inline long long pow(const long long &base, int ext)
{
	long long ret = 1;
	while(ext--)
		ret *= base;
	return ret;
}

int main()
{
	long long n;
	scanf("%lld", &n);
	for(int i = 60; i >= 0; --i)
		if(pow(2, i) <= n)
		{
			printf("%d", i);
			break;
		}
	return 0;
}