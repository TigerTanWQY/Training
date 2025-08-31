#include <bits/stdc++.h>
using namespace std;

int a[1003];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i < n; ++i)
	{
		for(int j = i; j <= i + 1; ++j) //Ñ¡ÔñÅÅÐò
			for(int k = j + 1; k <= n; ++k)
				if(a[k] < a[j])
					swap(a[j], a[k]);
		a[i + 1] += a[i];
		ans += a[i + 1];
	}
	printf("%d", ans);
	return 0;
}