#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int a[200003], b[200003];

int main()
{
	int n, m, ans = INT_MAX;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < m; ++i)
		scanf("%d", &b[i]);
	sort(a, a + n);
	sort(b, b + m);
	for(int x = 0, y = 0; x < n && y < m; )
	{
		ans = min(ans, abs(a[x] - b[y]));
		if(a[x] > b[y])
			++y;
		else
			++x;
	}
	printf("%d", ans);
	return 0;
}