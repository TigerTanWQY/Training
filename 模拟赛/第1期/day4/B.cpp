#include <cstdio>
using namespace std;

int a[100003], n;

int gcd(const int &x, const int &y)
{
	if(y == 0)
		return x;
	else
		return gcd(y, x % y);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int ans = a[1];
	for(int i = 2; i <= n; ++i)
		ans = gcd(ans, a[i]);
	printf("%d", ans);
	return 0;
}