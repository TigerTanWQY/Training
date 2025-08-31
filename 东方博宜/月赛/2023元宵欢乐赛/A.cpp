#include <bits/stdc++.h>
using namespace std;

int a[100003];
long long s[100003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		s[i] = 0LL + a[i] - a[i - 1];
	}
	int ans = 0, len = 0;
	long long last = s[1];
	for(int i = 1; i <= n + 1; ++i)
	{
		if(s[i] == last)
			++len;
		else
		{
			if(len >= 3)
				ans = max(ans, len);
			last = s[i];
			len = 2;
		}
	}
	printf("%d", ans);
	return 0;
}