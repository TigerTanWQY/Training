#include <bits/stdc++.h>
using namespace std;

char a[11];

int main()
{
	int n;
	scanf("%d", &n);
	int len = 0;
	while(n > 0)
	{
		int tmp = n % 16;
		if(tmp >= 10)
			a[++len] = tmp - 10 + 'A';
		else
			a[++len] = tmp + '0';
		n /= 16;
	}
	for(int i = len; i >= 1; --i)
		printf("%c", a[i]);
	return 0;
}