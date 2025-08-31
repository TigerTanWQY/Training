#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<bool> s;
vector<pair<int, int>> op;
unordered_map<int, int> tmp, used;

int main()
{
	int n, m = 0, cnt = 0, ans = 0;
	scanf("%d", &n);
	op.push_back({});
	for(int i = 1; i <= n; ++i)
	{
		int t, x;
		scanf("%d%d", &t, &x);
		op.push_back({t, x});
		if(t == 2)
			++tmp[x];
	}
	for(int i = 1; i <= n; ++i)
	{
		int t = op[i].first, x = op[i].second;
		if(t == 1)
			if(tmp.count(x) && tmp[x])
			{
				++used[x];
				s.push_back(true);
				++cnt;
			}
			else
				s.push_back(false);
		else
			if(used.count(x) && used[x])
			{
				--used[x];
				--cnt;
				--tmp[x];
			}
			else
			{
				printf("-1");
				return 0;
			}
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
	for(const auto &p: s)
	{
		if(p)
			putchar('1');
		else
			putchar('0');
		putchar(' ');
	}
	return 0;
}
