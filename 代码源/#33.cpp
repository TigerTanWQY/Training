#include <bits/stdc++.h>
using namespace std;

int p[1000003];

int main()
{
	int n, d;
	scanf("%d%d", &n, &d);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &p[i]);
	sort(p + 1, p + n + 1);
	int ans = 0;
	for(int i = 1; i < n; ++i)
		for(int j = i + 1; j <= n; ++j) //这一个循环如何优化
			if(p[j] - p[i] <= d)
				++ans;
	printf("%d", ans);
	return 0;
}