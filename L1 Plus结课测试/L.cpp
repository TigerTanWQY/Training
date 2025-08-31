#include <bits/stdc++.h>
using namespace std;

char a[34];

int main()
{
	int m;
	scanf("%d", &m);
	while(m--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		int len = 0;
		while(n > 0)
		{
			int tmp = n % k;
			if(tmp >= 10)
				a[++len] = tmp - 10 + 'A';
			else
				a[++len] = tmp + '0';
			n /= k;
		}
		for(int i = len; i > 0; --i)
			printf("%c", a[i]);
		printf("\n");
	}
	return 0;
}