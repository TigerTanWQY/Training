#include <cstdio>
#include <algorithm>
using namespace std;

struct Data
{
	int s, e, w;
	bool operator<(const Data &A) const
	{
		if(e != A.e)
			return e < A.e;
		else if(w != A.w)
			return w > A.w;
		else
			return s > A.s;
	}
} a[1003];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d%d", &a[i].s, &a[i].e, &a[i].w);
	sort(a + 1, a + n + 1);
	for(int i = 1, e = 0; i <= n; ++i)
		if(a[i].s >= e)
		{
			ans += a[i].w;
			e = a[i].e;
		}
	printf("%d", ans);
	return 0;
}