#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Happy
{
	char x, y;
	int c;
	bool operator<(const Happy &A) const
	{
		if(c != A.c)
			return c > A.c;
		else
			return false;
	}
} a[679];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int k, n, ans = 0;
	cin >> s >> k >> n;
	int len = s.size();
	for(int i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y >> a[i].c;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n && k; ++i)
	{
		int p = s.find(a[i].x), q = s.find(a[i].y);
		if(p < len - 1)
		{
			if(s[p + 1] != a[i].y && k)
			{
				--k;
				s[p + 1] = a[i].y;
			}
			if(k >= 0)
				ans += a[i].c;
		}
		if(0 < q && q < len)
		{
			if(s[q - 1] != a[i].x && k)
			{
				--k;
				s[q - 1] = a[i].x;
			}
			if(k >= 0)
				ans += a[i].c;
		}
	}
	printf("%d", ans);
	return 0;
}