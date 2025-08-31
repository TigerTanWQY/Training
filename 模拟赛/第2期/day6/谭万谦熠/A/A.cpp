#include <cstdio>
#include <climits>
#include <map>
using namespace std;

int a[200003];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		map<int, int> cnt;
		int n, maxi = 0, ans = INT_MAX;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", &a[i]);
			maxi = max(maxi, a[i]);
		}
		for(int x = 1; x <= maxi; ++x)
		{
			int tot = 0;
			for(int i = 1; i <= n; )
			{
				if(a[i] != x)
				{
					++tot;
					for(; a[i] != x && i <= n; ++i);
				}
				for(; a[i] == x && i <= n; ++i);
			}
			ans = min(ans, tot);
		}
		printf("%d\n", ans);
	}
	return 0;
}