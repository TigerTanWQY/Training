#include <bits/stdc++.h>
using namespace std;

int gcd(const int &a, const int &b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
	return 0;
}