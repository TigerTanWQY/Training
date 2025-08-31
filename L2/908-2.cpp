#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int q[N + 3];
int f = 1, r = N;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		r = r % N + 1;
		q[r] = i;
	}
	int x = 0;
	while(r % N + 1 - f != 0)
	{
		int y = q[f];
		f = f % N + 1;
		++x;
		if(x == m)
		{
			printf("%d ", y);
			x = 0;
		}
		else
		{
			r = r % N + 1;
			q[r] = y;
		}
	}
	return 0;
}