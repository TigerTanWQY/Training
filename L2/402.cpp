#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 100000000;
	for(int i = 1; i <= 3; ++i)
	{
		int num, price;
		scanf("%d%d", &num, &price);
		int now = ceil(1.0 * n / num) * price;
		if(now < ans)
			ans = now;
	}
	printf("%d", ans);
	return 0;
}