#include <cstdio>
#include <algorithm>
using namespace std;

int r[103], f[103];
char s[103][103];

bool cmp(const int &x, const int &y)
{
	if(f[x] != f[y])
		return f[x] > f[y];
	else
		return x < y;
}

int check(const char &x, const char &y)
{
	if(x == y)
		return -1;
	return !((x == 'G' && y == 'C') || (x == 'C' && y == 'P') || (x == 'P' && y == 'G'));
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	n <<= 1;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%s", s[i] + 1);
		r[i] = i;
	}
	for(int i = 1; i <= m; ++i)
	{
		for(int j = 2; j <= n; j += 2)
		{
			int k = check(s[r[j - 1]][i], s[r[j]][i]);
			if(k != -1)
				++f[r[j - 1 + k]];
		}
		sort(r + 1, r + n + 1, cmp);
	}
	for(int i = 1; i <= n; ++i)
		printf("%d\n", r[i]);
	return 0;
}