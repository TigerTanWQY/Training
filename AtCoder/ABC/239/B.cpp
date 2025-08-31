#include <cstdio>
using namespace std;

int main()
{
	long long x;
	scanf("%lld", &x);
	if(x < 0)
		printf("%lld", x / 10 - !!(x % 10));
	else
		printf("%lld", x / 10);
	return 0;
}