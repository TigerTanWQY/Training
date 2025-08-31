#include <cstdio>
using namespace std;

char a[103][103];

bool check(const int &x, const int &y)
{
	for(int i = x; i < x + 3; ++i)
		for(int j = y; j < y + 3; ++j)
			if(a[i][j] != '#')
				return false;
	for(int i = x + 6; i < x + 9; ++i)
		for(int j = y + 6; j < y + 9; ++j)
			if(a[i][j] != '#')
				return false;
	for(int i = x; i <= x + 3; ++i)
		if(a[i][y + 3] != '.')
			return false;
	for(int j = y; j <= y + 3; ++j)
		if(a[x + 3][j] != '.')
			return false;
	return true;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%s", a[i] + 1);
	for(int i = 1; i <= n - 8; ++i)
		for(int j = 1; j <= m - 8; ++j)
			if(check(i, j))
				printf("%d %d\n", i, j);
	return 0;
}