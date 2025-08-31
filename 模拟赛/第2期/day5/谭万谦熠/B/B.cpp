#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int a[100003];

int main()
{
	int T;
	scanf("%d", &T);
	for(int n, L, R, ans; T--; )
	{
		scanf("%d", &n);
		L = INT_MAX;
		R = INT_MIN;
		ans = 0;
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", &a[i]);
			if(a[i] > 0)
			{
				if(abs(a[i] % 2))
					L = min(L, a[i]);
				ans += a[i];
			}
			if(a[i] < 0 && abs(a[i]) % 2)
				R = max(R, a[i]);
		}
		if(!(ans % 2))
			ans = max(ans - L, ans + R);
		printf("%d\n", ans);
	}
	return 0;
}