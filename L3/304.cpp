#include <bits/stdc++.h>
using namespace std;

bool a[1000003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x] = true;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(!a[i])
			++ans;
	printf("%d", ans);
	return 0;
}