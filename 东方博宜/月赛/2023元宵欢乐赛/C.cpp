#include <bits/stdc++.h>
using namespace std;

int a[703][703];
bool is_peek[703][703];
int ans = 0;

void func(int i, int j)
{
	if(a[i][j] == 0)
		;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	func(1, 1);
	printf("%d", ans);
	return 0;
}