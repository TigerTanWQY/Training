#include <cstdio>
#include <cstdlib>
using namespace std;

char G[503][503];
int H, W;

void dfs(const int &i, const int &j, const int &cnt)
{
	if(cnt > H * W)
	{
		printf("-1");
		exit(0);
	}
	if(G[i][j] == 'U' && i != 1)
		dfs(i - 1, j, cnt + 1);
	else if(G[i][j] == 'D' && i != H)
		dfs(i + 1, j, cnt + 1);
	else if(G[i][j] == 'L' && j != 1)
		dfs(i, j - 1, cnt + 1);
	else if(G[i][j] == 'R' && j != W)
		dfs(i, j + 1, cnt + 1);
	else
	{
		printf("%d %d", i, j);
		return;
	}
}

int main()
{
	scanf("%d%d", &H, &W);
	for(int i = 1; i <= H; ++i)
		scanf("%s", G[i] + 1);
	dfs(1, 1, 0);
	return 0;
}
