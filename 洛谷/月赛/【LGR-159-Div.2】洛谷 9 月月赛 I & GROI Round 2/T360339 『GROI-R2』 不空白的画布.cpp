#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		vector<int> c(n + 3);
		vector<vector<int>> f(n + 3, vector<int>(m + 3));
		for(int i = 1; i <= n; ++i)
			scanf("%d", &c[i]);
		c[0] = -114;
		c[n + 1] = -514;
		f[1][0] = 1;
		for(int i = 2; i <= n; ++i)
			f[i][0] = f[i - 1][0] + (c[i + 1] == c[i - 1]? k > 1: k > 2);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				f[i][j] = max({f[i][j], f[i - 1][j] + (c[i] != c[i - 1]), f[i - 1][j - 1] + (c[i + 1] == c[i - 1]? k > 1: k > 2)});
		printf("%d\n", f[n][m]);
	}
	return 0;
}