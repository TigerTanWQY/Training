#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		printf("%d ", x + m);
	}
	return 0;
}