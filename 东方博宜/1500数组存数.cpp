#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<int>> a(n + 3);
	while(m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
	}
	for(int i = 1; i <= n; ++i)
	{
		m = a[i].size();
		printf("%d ", m);
		sort(a[i].begin(), a[i].end());
		for(int j = 0; j < m; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}