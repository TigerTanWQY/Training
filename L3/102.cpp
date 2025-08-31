#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	if(n == 1)
		printf("1");
	else if(n == 2)
		printf("2");
	else
	{
		int x = 1, y = 2, z = x + y;
		for(int i = 3; i <= n; ++i)
		{
			z = x + y;
			x = y;
			y = z;
		}
		printf("%d", z);
	}
	return 0;
}