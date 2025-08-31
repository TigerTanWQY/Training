#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int w[33], f[33];

int main()
{
	int V, n, ans = 200001;
	scanf("%d%d", &V, &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &w[i]);
	for(int i = 1; i <= n; ++i)
	{
		f[i] = (V - w[i] >= 0? V - w[i]: 200001);
		for(int j = 1; j < i; ++j)
			if(f[j] != 200001 && f[j] - w[i] >= 0)
				f[i] = min(f[i], f[j] - w[i]);
		ans = min(ans, f[i]);
	}
	printf("%d", ans);
	return 0;
}