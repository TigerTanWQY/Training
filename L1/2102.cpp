#include <bits/stdc++.h>
using namespace std;

int add(int x, int y)
{ return x + y; }

int dec(int x, int y)
{ return x - y; }

int mul(int x, int y)
{ return x * y; }

int divi(int x, int y)
{ return x / y; }

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n%d\n%d\n%d", add(a, b), dec(a, b), mul(a, b), divi(a, b));
	return 0;
}