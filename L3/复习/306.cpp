#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000003;
const int INF = 0x3f3f3f3f;
vector<int> G[N];
int a[N], d[N]{0, 1}, f[N], v[N], ans = 0;

void dfs(const int &p)
{
	f[p] = INF;
	v[p] = d[p] - a[p] + 1;
	for(const auto &x: G[p])
	{
		d[x] = d[p] + 1;
		dfs(x);
		f[p] = min(f[p], f[x]);
		v[p] = min(v[p], v[x]);
	}
	if(f[p] > d[p])
	{
		++ans;
		f[p] = v[p];
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
	}
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	dfs(1);
	printf("%d", ans);
	return 0;
}