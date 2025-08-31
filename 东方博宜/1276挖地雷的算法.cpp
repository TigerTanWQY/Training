#include <bits/stdc++.h>
using namespace std;

vector<int> edges[203];
int a[203], f[203], r[203];
bool b[203][203];

int main()
{
	int n, idx;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	while(true)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if(x == 0 && y == 0)
			break;
		b[x][y] = true;
	}
	f[n] = a[n];
	for(int i = n - 1; i >= 1; --i)
	{
		int cnt = 0;
		for(int j = i + 1; j <= n; ++j)
			if(b[i][j] && f[j] > cnt)
			{
				idx = j;
				cnt = f[j];
			}
		f[i] = a[i] + cnt;
		r[i] = idx;
	}
	idx = 1;
	for(int i = 2; i <= n; ++i)
		if(f[i] > f[idx])
			idx = i;
	int ans = f[idx];
	while(idx != 0)
	{
		printf("%d", idx);
		idx = r[idx];
		if(idx != 0)
			printf("-");
	}
	printf("\n%d", ans);
	return 0;
}