#include <bits/stdc++.h>
using namespace std;

int a[1003];

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	while(q--)
	{
		int len, num;
		scanf("%d%d", &len, &num);
		int base = 10;
		for(int i = 1; i < len; ++i)
			base *= 10;
		int ans = 10000001;
		for(int i = 1; i <= n; ++i)
			if(a[i] % base == num && a[i] < ans)
				ans = a[i];
		if(ans == 10000001)
			ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}