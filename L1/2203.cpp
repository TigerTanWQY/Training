#include <bits/stdc++.h>
using namespace std;

int a[1003], b[1003]; //b存放负数

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		if(x < 0)
			++b[-x];
		else
			++a[x];
	}
	for(int i = 1000; i > 0; --i)
		while(b[i]--)
			printf("%d ", -i);
	for(int i = 0; i <= 1000; ++i)
		while(a[i]--)
			printf("%d ", i);
	return 0;
}