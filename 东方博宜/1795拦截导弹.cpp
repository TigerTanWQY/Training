#include <bits/stdc++.h>
using namespace std;

int a[1003], f[1003];

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		f[i] = 1;
		for(int j = 1; j < i; ++j)
			if(a[i] < a[j])
				f[i] = max(f[i], f[j] + 1);
		ans = max(ans, f[i]);
	}
	printf("%d", ans);
	return 0;
}