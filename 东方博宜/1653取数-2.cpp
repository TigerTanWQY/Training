#include <cstdio>
#include <algorithm>
using namespace std;

int a[53], f[53];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	f[1] = a[1];
	f[2] = max(a[1], a[2]);
	for(int i = 3; i <= n; ++i)
		f[i] = max(f[i - 1], f[i - 2] + a[i]);
	printf("%d", f[n]);
	return 0;
}