#include <bits/stdc++.h>
using namespace std;

struct Line
{
	int a, b;
	int len;
	bool operator<(const Line &x) const
	{
		if(a == 1)
			return a != x.a;
		if(len != x.len)
			return len < x.len;
		return a < x.a;
	}
}
a[100003];
bool cover[100003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &a[i].a, &a[i].b);
		a[i].len = a[i].b - a[i].a;
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(cover[a[i].a])
			continue;
		for(int j = a[i].a; j <= a[i].b; ++j)
			cover[j] = true;
		++ans;
	}
	printf("%d", ans);
	return 0;
}