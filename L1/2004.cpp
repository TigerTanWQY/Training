#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	while(n > 0)
	{
		if((n & 1) == 1)
			++ans;
		n >>= 1;
	}
	printf("%d", ans);
	return 0;
}