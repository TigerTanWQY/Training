#include <bits/stdc++.h>
using namespace std;

int q[200003];
int f = 1, r = 0;

int main()
{
	int k;
	scanf("%d%d", &q[1], &k);
	++r;
	while(k--)
	{
		printf("%d\n", q[f]);
		q[++r] = 2 * q[f];
		q[++r] = 2 * q[f] + 1;
		++f;
	}
	return 0;
}