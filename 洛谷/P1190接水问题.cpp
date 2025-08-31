#include <cstdio>
using namespace std;

int w[10003];

int main()
{
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &w[i]);
	for(int t = m + 1; t <= n + m; ++ans)
		for(int i = 1; i <= m; ++i)
			if(!--w[i])
				w[i] = w[t++];
	printf("%d", ans);
	return 0;
}