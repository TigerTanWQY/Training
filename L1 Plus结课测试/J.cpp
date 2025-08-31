#include <bits/stdc++.h>
using namespace std;

int a[10003], s[10003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a + i);
		int x = a[i];
		while(x > 0)
		{
			s[i] += x % 10;
			x /= 10;
		}
	}
	for(int i = 1; i < n; ++i)
		for(int j = 1; j <= n - i; ++j)
			if(s[j] > s[j + 1])
			{
				swap(a[j], a[j + 1]);
				swap(s[j], s[j + 1]);
			}
			else if(s[j] == s[j + 1] && a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
	for(int i = n; i >= 1; --i)
		printf("%d ", a[i]);
	return 0;
}