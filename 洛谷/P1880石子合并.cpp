#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 203;
int a[N], f1[N][N], f2[N][N];

int dfs1(const int &L, const int &R)
{
	if(L == R)
		return 0;
	if(f1[L][R] != INF)
		return f1[L][R];
	int ret = INF;
	for(int i = L; i < R; ++i)
		ret = min(ret, dfs1(L, i) + dfs1(i + 1, R) + a[R] - a[L - 1]);
	return f1[L][R] = ret;
}

int dfs2(const int &L, const int &R)
{
	if(L == R)
		return 0;
	if(f2[L][R])
		return f2[L][R];
	int ret = 0;
	for(int i = L; i < R; ++i)
		ret = max(ret, dfs2(L, i) + dfs2(i + 1, R) + a[R] - a[L - 1]);
	return f2[L][R] = ret;
}

int main()
{
	int n, ans1 = INF, ans2 = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for(int i = 1; i <= 2 * n; ++i)
	{
		a[i] += a[i - 1];
		for(int j = 1; j <= 2 * n; ++j)
			f1[i][j] = INF;
	}
	dfs1(1, 2 * n);
	dfs2(1, 2 * n);
	for(int i = 1; i <= n; ++i)
	{
		ans1 = min(f1[i][n + i - 1], ans1);
		ans2 = max(f2[i][n + i - 1], ans2);
	}
	printf("%d\n%d", ans1, ans2);
	return 0;
}