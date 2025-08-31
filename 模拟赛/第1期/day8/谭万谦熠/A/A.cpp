#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int a[100003], m = 0;

int main()
{
	int n, ww, rng = 0, cnt = 0;
	scanf("%d%d", &n, &ww);
	for(int i = 2; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		if(x == -1)
			++cnt;
		else
			a[++m] = x;
	}
	a[++m] = ww;
	sort(a + 1, a + m + 1, greater<int>());
	for(int i = 1; i <= m; ++i)
		if(a[i] == ww && a[i - 1] != ww)
		{
			rng = i;
			break;
		}
	if(ww == 0 || ww == 100)
		cnt = 0;
	printf("%d %d", rng, rng + cnt);
	return 0;
}