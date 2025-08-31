#include <bits/stdc++.h>
using namespace std;

int a[1003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>());
	int ans = a[1] * 10;
	for(int i = 2; i <= 5; ++i)
		ans += a[i] * 8;
	for(int i = 6; i <= 10; ++i)
		ans += a[i] * 5;
	for(int i = 11; i <= n; ++i)
		ans += a[i];
	printf("%d", ans);
	return 0;
}