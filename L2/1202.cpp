#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = n; i >= 0; --i)
	{
		int x;
		scanf("%d", &x);
		if(x == 0)
			continue;
		if(x > 0)
		{
			if(i != n)
				printf("+");
		}
		else
			printf("-");
		int y = abs(x);
		if(y != 1)
			printf("%d", y);
		else if(i == 0)
			printf("%d", y);
		if(i >= 2)
			printf("x^%d", i);
		else if(i == 1)
			printf("x");
	}
	return 0;
}