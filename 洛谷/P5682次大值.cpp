#include <cstdio>
#include <algorithm>
using namespace std;

int a[200003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	n = unique(a + 1, a + n + 1) - a - 1;
	a[0] = 0;
	if(n <= 1)
		printf("-1");
	else
		printf("%d", max(a[n - 2], a[n] % a[n - 1]));
	return 0;
}