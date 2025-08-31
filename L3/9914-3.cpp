#include <bits/stdc++.h>
using namespace std;

int calc(const int &x, const int &y, const int &n)
{
	if(x == 1)
		return y;
	if(y == n)
		return x + n - 1;
	if(x == n)
		return -y + 3 * n - 1;
	if(y == 1)
		return -x + 4 * n - 2;
	return 0;
}

int main()
{
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	int m = min({x - 1, n - x, y - 1, n - y});
	printf("%d", 4 * m * (n - m) + calc(x - m, y - m, n - 2 * m));
	return 0;
}