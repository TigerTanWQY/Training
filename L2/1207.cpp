#include <bits/stdc++.h>
using namespace std;

const int MOD = 20123;
int stair[10003][103], num[10003][103];

int main()
{
	int n, m, pos, ans = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d%d", &stair[i][j], &num[i][j]);
	scanf("%d", &pos);
	for(int i = 1; i <= n; ++i)
	{
		int x = num[i][pos];
		ans = (ans + x) % MOD;
		/**优化**/
		int t = 0;
		for(int j = 0; j < m; ++j)
			t += stair[i][j];
		x %= t;
		if(x == 0)
			x = t;
		/**优化**/
		if(stair[i][pos])
			--x;
		while(x > 0)
		{
			pos = (pos + 1) % m;
			if(stair[i][pos])
				--x;
		}
	}
	printf("%d", ans);
	return 0;
}