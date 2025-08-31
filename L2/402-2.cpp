#include <bits/stdc++.h>
using namespace std;

int n;

int calc(int x, int y)
{
	int z = n / x;
	if(n % x != 0)
		++z;
	return y * z;
}

int main()
{
	int a1, b1, a2, b2, a3, b3;
	scanf("%d%d%d%d%d%d%d", &n, &a1, &b1, &a2, &b2, &a3, &b3);
	int x1 = calc(a1, b1), x2 = calc(a2, b2), x3 = calc(a3, b3);
	printf("%d", min(min(x1, x2), x3));
	return 0;
}