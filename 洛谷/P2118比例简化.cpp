#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, l;
	scanf("%d%d%d", &a, &b, &l);
	int ansa = l, ansb = 1;
	for(int i = 1; i <= l; ++i)
		for(int j = 1; j <= l; ++j)
			if(__gcd(i, j) == 1 && i * b >= j * a && i * ansb < j * ansa)
			{
				ansa = i;
				ansb = j;
			}
	printf("%d %d", ansa, ansb);
	return 0;
}