#include <cstdio>
#include <algorithm>
using namespace std;

int a[1003], f[1003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n / 2; ++i)
		for(int j = 2; i * j <= n; ++j)
			a[i * j] += i;
	for(int i = 1; i <= n; ++i)
		for(int j = n; j >= i; --j)
			f[j] = max(f[j], f[j - i] + a[i]);
	printf("%d", f[n]);
	return 0;
}