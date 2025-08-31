#include <bits/stdc++.h>
using namespace std;

int a[1003][1003], ma[1003], z[6]{2, 1, 0, 0, 0, 0}, s[6]{6, 6, 6, 6, 5, 4}, maxx = 0, maxy = 0;
char c[1003][1003], c1[10][10]{
	"  +---+",
	" /   /|",
	"+---+ |",
	"|   | +",
	"|   |/",
	"+---+"
};

inline void fg(const int &x, const int &y)
{
	for(int i = 5; i >= 0; --i)
		for(int j = z[i]; j <= s[i]; ++j)
		{
			c[5 - i + x][j + y] = c1[i][j];
			maxx = max(maxx, 5 - i + x);
			maxy = max(maxy, j + y);
		}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
	for(int o = 1; o <= n; ++o)
		for(int k = 0; k < m; ++k)
			for(int l = 0; l < a[o][k]; ++l)
				fg((n - o) * 2 + 1 + 3 * l, (n - o) * 2 + 1 + 4 * k);
	for(int i = maxx; i >= 1; --i)
	{
		for(int j = 1; j <= maxy; ++j)
			if(c[i][j] == '\0')
				printf(".");
			else
				printf("%c", c[i][j]);
		printf("\n");
	}
	return 0;
}