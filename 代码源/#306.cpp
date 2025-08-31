#include <cstdio>
using namespace std;

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	while(n--)
		m /= 10;
	printf("%d", m);
	return 0;
}