#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		int x, y, z, k, s;
		scanf("%d%d%d%d%d", &x, &y, &z, &k, &s);
		while(s--) //Ч���д����
		{
			if(x < k)
				x += y;
			else
				x -= z;
		}
		printf("%d\n", x);
	}
	return 0;
}