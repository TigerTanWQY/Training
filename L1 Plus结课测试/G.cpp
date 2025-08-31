#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	while(n--)
	{
		int x;
		scanf("%d", &x);
		bool flag = false;
		while(x > 0)
		{
			if(x % 10 == 7)
			{
				flag = true;
				break;
			}
			x /= 10;
		}
		if(flag)
			++ans;
	}
	printf("%d", ans);
	return 0;
}