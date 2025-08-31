#include <bits/stdc++.h>
using namespace std;

const int N = 5001;
int q[N + 3];
int f = 1, r = N;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		r = r % N + 1;
		q[r] = i;
	}
	int i = 1, cnt = 0;
	while(i <= n)
	{
		++cnt;
		if(cnt == i * i)
		{
			printf("%d ", q[f]);
			cnt = 0;
			++i;
		}
		else
		{
			r = r % N + 1;
			q[r] = q[f];
		}
		f = f % N + 1;
	}
	return 0;
}