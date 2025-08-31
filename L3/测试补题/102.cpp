#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> edges[100003];
pair<int, int> ans[100003];
int tmp[100003], len, n;

inline void init()
{
	for(int i = 1; i < 100003; ++i)
	{
		edges[i].clear();
		ans[i].first = 0;
		ans[i].second = INT_MAX;
	}
	len = 0;
}

inline void input()
{
	scanf("%d", &n);
	for(int _ = 1; _ < n; ++_)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
	}
}

void dfs(const int &p)
{
	tmp[++len] = p;
	ans[p].first = max(ans[p].first, len);
	ans[p].second = min(ans[p].second, len);
	do
	{
		for(const auto &x: edges[p])
			dfs(x);
	} while(next_permutation(edges[p].begin(), edges[p].end())); //获取全排列
}

inline void solve()
{
	for(int i = 1; i < 100003; ++i)
		sort(edges[i].begin(), edges[i].end()); //排序
	dfs(1);
}

inline void output()
{
	for(int i = 1; i <= n; ++i)
		printf("%d %d\n", ans[i].first, ans[i].second);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		init();
		input();
		solve();
		output();
	}
	return 0;
}