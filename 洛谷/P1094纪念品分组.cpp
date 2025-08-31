#include <cstdio>
#include <algorithm>
using namespace std;

int p[30003];

int main()
{
	int w, n;
	scanf("%d%d", &w, &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &p[i]);
	sort(p + 1, p + n + 1);
	int ans = n;
	for(int i = 1, j = n; j > i; --j)
		if(p[i] + p[j] <= w)
		{
			++i;
			--ans;
		}
	printf("%d", ans);
	return 0;
}