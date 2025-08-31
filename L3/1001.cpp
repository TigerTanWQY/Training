#include <bits/stdc++.h>
using namespace std;

int f[100003][20];

int main()
{
	int n, m;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		f[y][0] = x;
	}
	for(int j = 1; j <= 17; ++j)
		for(int i = 1; i <= n; ++i)
			f[i][j] = f[f[i][j - 1]][j - 1];
	scanf("%d", &m);
	while(m--)
	{
		int p, c;
		scanf("%d%d", &p, &c);
		for(int i = 0; c; c /= 2, ++i) //二进制拆分
			if(c & 1) //如果当前二进制位存在
				p = f[p][i];
		if(p == 0)
			printf("-1\n");
		else
			printf("%d\n", p);
	}
	return 0;
}