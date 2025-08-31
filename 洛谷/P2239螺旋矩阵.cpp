#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, i, j;
	scanf("%d%d%d", &n, &i, &j);
	int minn = min({i, j, n - i + 1, n - j + 1});
	if(i <= j)
		printf("%d", minn * (4 * (n - 1) - 4 * minn) + 10 * minn - 4 * n - 3 + i + j);
	else
		printf("%d", minn * (4 * n - 4 * minn) + 2 * minn + 1 - i - j);
	return 0;
}