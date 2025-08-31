#include <cstdio>
using namespace std;

const int N = 13;
int n;
bool flag[N][N], col[N], Mdg[2 * N], Ddg[2 * N];

void dfs(const int &x)
{
	if(x > n) //output
	{
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(flag[i][j])
					printf("%d ", j);
		printf("\n");
	}
	for(int i = 1; i <= n; ++i)
		if(!col[i] && !Mdg[i - x + n] && !Ddg[i + x]) //solve
		{
			flag[x][i] = col[i] = Mdg[i - x + n] = Ddg[i + x] = true;
			dfs(x + 1);
			flag[x][i] = col[i] = Mdg[i - x + n] = Ddg[i + x] = false;
		}
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	return 0;
}