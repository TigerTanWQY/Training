#include <bits/stdc++.h>
using namespace std;

int a[13];

int main()
{
	int x;
	for(int i = 1; i <= 10; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &x);
	x += 30;
	int ans = 0;
	for(int i = 1; i <= 10; ++i)
		if(x >= a[i])
			++ans;
	printf("%d", ans);
	return 0;
}