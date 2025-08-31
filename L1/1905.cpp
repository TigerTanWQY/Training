#include <bits/stdc++.h>
using namespace std;

int a[13];

int main()
{
	int n;
	scanf("%d", &n);
	int len = 0;
	while(n > 0)
	{
		a[++len] = n % 8;
		n /= 8;
	}
	for(int i = len; i >= 1; --i)
		printf("%d", a[i]);
	return 0;
}