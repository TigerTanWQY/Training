#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int a[1000003];

int main()
{
	freopen("sort.in", "r", stdin);
	freopen("sort.ans", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>()); // Õæ¡¤±©Á¦
	for(int i = 1; i <= m; ++i)
		printf("%d ", a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}