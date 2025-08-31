#include <bits/stdc++.h>
using namespace std;

int a[1003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	if(n % 2)
		for(int i = 1; i <= n / 2 + 1; ++i)
			printf("%d ", a[i * 2 - 1]);
	else
		for(int i = 1; i <= n / 2; ++i)
			printf("%d ", a[i * 2 - 1]);
	for(int i = 1; i <= n / 2; ++i)
		printf("%d ", a[i * 2]);
	return 0;
}