#include <bits/stdc++.h>
using namespace std;

bool used[20003];
int a[103];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		used[a[i]] = true;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(used[a[i] + a[j]])
			{
				++ans;
				used[a[i] + a[j]] = false;
			}
	printf("%d", ans);
	return 0;
}