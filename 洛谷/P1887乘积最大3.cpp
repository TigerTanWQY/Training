#include <cstdio>
using namespace std;

int a[1000003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
		a[i] = n / m;
	for(int i = m, x = n % m; i >= 1 && x; --i, --x)
		++a[i];
	for(int i = 1; i <= m; ++i)
		printf("%d ", a[i]);
	return 0;
}