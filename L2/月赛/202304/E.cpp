#include <bits/stdc++.h>
using namespace std;

int a[1503][1503], b[1503][1503];
int s[1503], t[1503];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			scanf("%d", &a[i][j]);
			s[i] += a[i][j];
		}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			scanf("%d", &b[i][j]);
			t[i] += b[i][j];
		}
	int minn = 1500000000;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			minn = min(minn, abs(s[i] - t[j]));
	printf("%d", minn);
	return 0;
}