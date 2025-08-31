#include <bits/stdc++.h>
using namespace std;

int count2(int x)
{
	int ret = 0;
	while(x > 0)
	{
		if(x % 10 == 2)
			++ret;
		x /= 10;
	}
	return ret;
}

int main()
{
	int L, R;
	scanf("%d%d", &L, &R);
	int ans = 0;
	for(int i = L; i <= R; ++i)
		ans += count2(i);
	printf("%d", ans);
	return 0;
}