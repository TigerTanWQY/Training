#include <cstdio>
using namespace std;
using LL = long long;

int main()
{
	LL n;
	scanf("%lld", &n);
	while(n % 2 == 0)
		n /= 2;
	while(n % 3 == 0)
		n /= 3;
	if(n == 1)
		printf("Yes");
	else
		printf("No");
	return 0;
}