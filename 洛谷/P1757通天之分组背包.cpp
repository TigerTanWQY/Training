#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10003;
vector<int> G[103];
int a[N], b[N], f[N];

int main()
{
	int m, n, t = 0;
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= 101; ++i)
		G[i].push_back(-1);
	for(int i = 1; i <= n; ++i)
	{
		int c;
		scanf("%d%d%d", &a[i], &b[i], &c);
		t = max(t, c);
		G[c].push_back(i);
	}
	for(int i = 1; i <= t; ++i)
		for(int j = m; j >= 0; --j) //为什么 0 或 1 都可以 AC？
		{
			int len = G[i].size() - 1;
			for(int k = 1; k <= len; ++k)
				if(j >= a[G[i][k]])
					f[j] = max(f[j], f[j - a[G[i][k]]] + b[G[i][k]]);
		}
	printf("%d", f[m]);
	return 0;
}