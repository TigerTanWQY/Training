#include <bits/stdc++.h>
using namespace std;

int a[100003];
int n;

int calc(int x)
{
	int L = 0, R = n + 1;
	while(L + 1 < R)
	{
		int M = (L + R) >> 1;
		if(a[M] < x)
			L = M;
		else if(a[M] > x)
			R = M;
		else
			return M;
	}
	return -1;
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	while(m--)
	{
		int x;
		scanf("%d", &x);
		printf("%s\n", calc(x) != -1? "Yes": "No");
	}
	return 0;
}