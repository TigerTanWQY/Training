#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int a[15003], b[15003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int ans = a[n] - a[1] + 1;
	for(int i = 1; i < n; ++i)
		b[i] = a[i + 1] - a[i];
	sort(b + 1, b + n, greater<int>());
	for(int i = 1; i < m; ++i)
		ans -= b[i] - 1;
	printf("%d", ans);
	return 0;
}