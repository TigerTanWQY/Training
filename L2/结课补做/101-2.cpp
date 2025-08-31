#include <bits/stdc++.h>
using namespace std;

int q[25000003];
int f = 1, r = 0;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		q[++r] = i;
	int i = 1, cnt = 0;
	while(i <= n)
	{
		int pos = i * i % (r - f + 1);
		if(pos == 0)
			pos = r - f + 1;
		++cnt;
		if(cnt == pos)
		{
			printf("%d ", q[f]);
			++i;
			cnt = 0;
		}
		else
			q[++r] = q[f];
		++f;
	}
	return 0;
}