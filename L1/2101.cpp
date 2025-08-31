#include <bits/stdc++.h>
using namespace std;

int fac(int x)
{
	int ret = 1;
	for(int i = 2; i <= x; ++i)
		ret *= i;
	return ret;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", fac(n));
	return 0;
}