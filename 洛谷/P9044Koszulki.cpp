#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int a[2003];

int main()
{
	int n, k, cnt = 0;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>());
	for(int i = 1; ; ++i)
		if(i <= k || (i > k && a[i] == a[i - 1]))
			++cnt;
		else
			break;
	printf("%d", cnt);
	return 0;
}