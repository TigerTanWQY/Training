#include <cstdio>
#include <algorithm>
using namespace std;

int a[100003], b[100003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &b[i]);
	sort(b + 1, b + m + 1);
	for(int i = 1; i <= n; ++i)
		if(*lower_bound(b + 1, b + m + 1, a[i]) == a[i])
			printf("%d ", a[i]);
	return 0;
}