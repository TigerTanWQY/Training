#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m, s, t, ans;
	scanf("%d%d%d", &m, &s, &t);
	bool escape = false;
	for(int c = 0; c <= 6; ++c)
	{
		int mp = m, d = 0;
		for(int i = 1; i <= t; ++i)
		{
			if(i <= c)
				d += 17;
			else if(mp >= 10)
			{
				mp -= 10;
				d += 60;
			}
			else
				mp += 4;
			if(d >= s)
			{
				if(!escape)
				{
					escape = true;
					ans = i;
				}
				else
					ans = min(ans, i);
				break;
			}
		}
		if(d < s && !escape)
			ans = max(ans, d);
	}
	if(escape)
		printf("Yes");
	else
		printf("No");
	printf("\n%d", ans);
	return 0;
}