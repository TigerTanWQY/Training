#include <bits/stdc++.h>
using namespace std;

int a[100003];
long long s[100003], t[100003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
		t[i] = min(t[i - 1], s[i]);
	}
	long long ans = -10000000000;
	for(int i = m; i <= n; ++i)
		ans = max(ans, s[i] - t[i - m]);
	printf("%lld", ans);
	return 0;
}