#include <bits/stdc++.h>
using namespace std;

const int dx[]{-1, 0, 1, 0, 0, 0, -1, 0, 1};
const int dy[]{-1, -1, -1, 0, 0, 0, 1, 1, 1};
vector<pair<int, int>> c;
bool attack[13][13];
int ans[103], n, m = 0;

void dfs(const int &x, const int &y, const int &id)
{
	if(x < 1 || n < x || y < 1 || y < n)
	{
		if(id == 8)
		{
			for(int i = 1; i <= m; ++i)
				printf("%d ", ans[i]);
			printf("\n");
		}
		return;
	}
	for(int d = 1; d <= 8; ++d)
		for(int i = 0; i < 9; ++i)
			for(int j = 0; j < 9; ++j)
			{
				int tx = x + dx[i] * d, ty = y + dy[j] * d;
				if(!attack[tx][ty])
					c.push_back({tx, ty});
				attack[tx][ty] = true;
			}
	ans[++m] = y;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(!attack[i][j])
				dfs(i, j, id + 1);
	--m;
	for(const auto &p: c)
		attack[p.first][p.second] = false;
	c.clear();
}

int main()
{
	scanf("%d", &n);
	dfs(1, 1, 1);
	return 0;
}