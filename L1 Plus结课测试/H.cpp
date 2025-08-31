#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int h = 0, l = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			int x;
			scanf("%d", &x);
			if(x)
			{
				h = i;
				l = j;
				break;
			}
		}
	int ans = 0;
	if(h != 1)
		++ans;
	if(l != 1)
		++ans;
	cout << ans;
	return 0;
}