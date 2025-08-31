#include <bits/stdc++.h>
using namespace std;

int a[100003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	while(m--)
	{
		int x;
		scanf("%d", &x);
		int L = 0, R = n + 1;
		while(L + 1 < R)
		{
			int M = (L + R) >> 1;
			if(a[M] < x)
				L = M;
			else
				R = M;
		}
		if(R <= n && a[R] == x)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}