#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
struct Line
{
	int l, r, len;
	bool operator<(const Line &A) const
	{
		if(len != A.len)
			return len > A.len;
		else
			return abs(n / 2 - l) < abs(n / 2 - A.l);
	}
} a[200003];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d%d", &a[i].l, &a[i].r);
			a[i].len = a[i].r - a[i].l;
		}
		sort(a + 1, a + n + 1);
		for(int i = 2; i <= n; ++i) // 以 a[1] 为基准，让剩下的线段与之相交，否则删除
			if(a[i].r < a[1].l || a[i].l > a[1].r)
				++ans;
		printf("%d\n", ans);
	}
	return 0;
}