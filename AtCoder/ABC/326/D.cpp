#include <cstdio>
#include <cstdlib>
using namespace std;

const int d[7][5]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
char r[8], c[8], f[8][8];
int n;

void check()
{
	for(int i = 1; i <= n; ++i)
	{
		int cnta = 0, cntb = 0, cntc = 0;
		for(int j = 1; j <= n; ++j)
			switch(f[i][j])
			{
				case 'A':
					++cnta;
					break;
				case 'B':
					++cntb;
					break;
				case 'C':
					++cntc;
					break;
			}
		if(cnta != 1 || cntb != 1 || cntc != 1)
			return;
	}
	for(int j = 1; j <= n; ++j)
	{
		int cnta = 0, cntb = 0, cntc = 0;
		for(int i = 1; i <= n; ++i)
			switch(f[i][j])
			{
				case 'A':
					++cnta;
					break;
				case 'B':
					++cntb;
					break;
				case 'C':
					++cntc;
					break;
			}
		if(cnta != 1 || cntb != 1 || cntc != 1)
			return;
	}
	for(int i = 1; i <= n; ++i)
	{
		int j = 1;
		for(; f[i][j] == '.'; ++j);
		if(f[i][j] != r[i])
			return;
	}
	for(int j = 1; j <= n; ++j)
	{
		int i = 1;
		for(; f[i][j] == '.'; ++i);
		if(f[i][j] != c[j])
			return;
	}
	printf("Yes\n");
	for(int i = 1; i <= n; ++i)
		printf("%s\n", f[i] + 1);
	exit(0);
}

void dfs(const int &x, const int &y)
{
	for(int i = 0; i < 4; ++i)
	{
		int tx = x + d[i][0], ty = y + d[i][1];
		if(f[tx][ty])
			continue;
		else if(tx >= n && ty >= n)
		{
			check();
			continue;
		}
		else if(1 > tx || 1 > ty)
			continue;
		f[tx][ty] = '.';
		dfs(tx, ty);
		f[tx][ty] = 'A';
		dfs(tx, ty);
		f[tx][ty] = 'B';
		dfs(tx, ty);
		f[tx][ty] = 'C';
		dfs(tx, ty);
	}
}

int main()
{
	scanf("%d%s%s", &n, r + 1, c + 1);
	f[1][1] = '.';
	dfs(1, 1);
	f[1][1] = 'A';
	dfs(1, 1);
	f[1][1] = 'B';
	dfs(1, 1);
	f[1][1] = 'C';
	dfs(1, 1);
	printf("No");
	return 0;
}