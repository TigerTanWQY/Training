#include <cstdio>
#include <climits>
#include <set>
using namespace std;

set<pair<int, int>> s;
int a[200003], k, ans = INT_MAX;

void solve(int cnt, int res)
{
	for(const auto &p: s)
	{
		cnt += p.first;
		if(cnt > k)
			break;
		res -= 2;
	}
	ans = min(ans, res);
}

int main()
{
	int n, cnt = 0, t = 0, res = 0;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		if(a[i] < 0)
			++cnt;
	}
	if(cnt > k)
	{
		printf("-1");
		return 0;
	}
	for(int i = 1; i <= n; ++i)
		if(a[i] < 0)
		{
			if(t > -1)
			{
				++res;
				if(t > 0)
					s.insert({t, i - 1});
				t = -1;
			}
		}
		else
			if(t > -1)
			{
				if(t > 0)
					++t;
			}
			else
			{
				t = 1;
				++res;
			}
	if(t > 0 && cnt + t <= k)
		solve(cnt + t, res - 1);
	solve(cnt, res);
	printf("%d", ans);
	return 0;
}