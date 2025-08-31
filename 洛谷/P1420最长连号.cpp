#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
	int n, cnt = 1, ans = 0;
	scanf("%d", &n);
	for(int x, last = INT_MIN; n--; last = x)
	{
		scanf("%d", &x);
		if(x == last + 1)
			++cnt;
		else
		{
			ans = max(ans, cnt);
			cnt = 1;
		}
	}
	ans = max(ans, cnt);
	printf("%d", ans);
	return 0;
}