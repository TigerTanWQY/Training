#include <cstdio>
using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d / %d = %d", n, m, n / m);
	if(n % m)
		printf(" ... %d", n % m);
	return 0;
}