#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int h[20003];

int main()
{
	int n, b;
	scanf("%d%d", &n, &b);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &h[i]);
	sort(h + 1, h + n + 1, greater<int>());
	for(int i = 1, tot = 0; i <= n; ++i)
	{
		tot += h[i];
		if(tot >= b)
		{
			printf("%d", i);
			break;
		}
	}
	return 0;
}