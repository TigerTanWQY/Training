#include <bits/stdc++.h>
using namespace std;

int a[100003], cnt[603];

int main()
{
	int n, w;
	scanf("%d%d", &n, &w);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
	{
		int k = max(1, i * w / 100);
		cnt[a[i]]++;
		int s = 0;
		for(int j = 600; j >= 0; --j)
		{
			if(k >= s + 1 && k <= s + cnt[j])
			{
				printf("%d ", j);
				break;
			}
			s += cnt[j];
		}
	}
	return 0;
}