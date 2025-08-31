#include <bits/stdc++.h>
using namespace std;

int a[1003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>());
	for(int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}