#include <bits/stdc++.h>
using namespace std;

const auto DELTA = 1000;
int a[2003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		++a[x + DELTA];
	}
	for(int i = 0; i <= 2000; ++i)
		while(a[i]--)
			printf("%d ", i - DELTA);
	return 0;
}