#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		int m = 0, x = n;
		while(x > 0)
		{
			m += x % 10;
			x /= 10;
		}
		if(n % m == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}