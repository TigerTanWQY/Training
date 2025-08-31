#include <bits/stdc++.h>
using namespace std;

int a[103];

int solve(int opt, int l, int r)
{
	int ret;
	if(opt == 1)
	{
		ret = 1000000000;
		for(int i = l; i <= r; ++i)
			if(a[i] < ret)
				ret = a[i];
	}
	else/* if(opt == 2)*/
	{
		ret = 0;
		for(int i = l; i <= r; ++i)
			if(a[i] > ret)
				ret = a[i];
	}
	return ret;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	while(m--)
	{
		int opt, l, r;
		scanf("%d%d%d", &opt, &l, &r);
		printf("%d\n", solve(opt, l, r));
	}
	return 0;
}