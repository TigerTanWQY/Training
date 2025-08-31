#include <cstdio>
#include <algorithm>
using namespace std;

int f[103];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &f[i]);
	int ans = f[1];
	for(int i = 2; i <= n; ++i)
		ans = max(ans, f[i] = max(f[i - 1] + f[i], f[i]));
	printf("%d", ans);
	return 0;
}