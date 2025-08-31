#include <bits/stdc++.h>
using namespace std;

const int N = 1000003;
struct Node
{
	long long x, y;
	bool operator<(const Node &A) const
	{ return x * A.y > A.x * y; }
} a[N];
char s[N];

int main()
{
	int n;
	long long ans = 0, p = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%s", s + 1);
		for(int j = 1; s[j]; ++j)
			if(s[j] == 'X')
				++a[i].x;
			else
			{
				a[i].y += (s[j] - '0');
				ans += (s[j] - '0') * a[i].x;
			}
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
	{
		ans += p * a[i].y;
		p += a[i].x;
	}
	printf("%lld", ans);
	return 0;
}