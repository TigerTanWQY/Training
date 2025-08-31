#include <cstdio>
using namespace std;

inline int pow(const int &base, int exp)
{
	int ret = 1;
	while(exp--)
		ret *= base;
	return ret;
}

int main()
{
	int a, n;
	scanf("%d%d", &a, &n);
	printf("%d", pow(a, n));
	return 0;
}