#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
using LL = long long;

int a[503];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		LL ans = INT_MAX;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		if(m == 0)
			for(int i = 1; i <= n; ++i)
			{
				LL tot = 0;
				for(int j = 1; j <= n; ++j)
				{
					int tmp = a[j] - a[i];
					if(tmp < 0)
						tot += abs(tmp);
					else if(tmp > 0)
					{
						int base = 1, cnt = 0;
						for(; base < a[i]; base *= 2)
							++cnt;
						tot += min(cnt + abs(base / 2 - a[i]), cnt + 1 + abs(base - a[i]));
					}
				}
				ans = min(ans, tot);
			}
		else
		{
			int len = n - m;
			for(int l = 1; l <= m; ++l)
				for(int i = l; i <= l + len - 1; ++i)
				{
					LL tot = 0;
					for(int j = l; j <= l + len - 1; ++j)
					{
						int tmp = a[j] - a[i];
						if(tmp < 0)
							tot += abs(tmp);
						else if(tmp > 0)
						{
							int base = 1, cnt = 0;
							for(; base < a[i]; base *= 2)
								++cnt;
							tot += min(cnt + abs(base / 2 - a[i]), cnt + 1 + abs(base - a[i]));
						}
					}
					ans = min(ans, tot);
				}
		}
		if(ans == INT_MAX)
			printf("0\n");
		else
			printf("%lld\n", ans);
	}
	return 0;
}