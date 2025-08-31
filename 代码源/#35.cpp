#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int a[1003];

int main()
{
	int n, cnt0 = 0, cnt5 = 0;
	scanf("%d", &n);
	bool flag = false;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		if(!a[i])
		{
			flag = true;
			++cnt0;
		}
		else
			++cnt5;
	}
	if(!flag)
	{
		printf("-1");
		return 0;
	}
	sort(a + 1, a + n + 1, greater<int>());
	for(int i = 1; i <= cnt5 / 9 * 9; ++i)
		printf("5");
	if(cnt5 / 9 * 9 == 0)
		cnt0 = 1;
	for(int i = 1; i <= cnt0; ++i)
		printf("0");
	return 0;
}