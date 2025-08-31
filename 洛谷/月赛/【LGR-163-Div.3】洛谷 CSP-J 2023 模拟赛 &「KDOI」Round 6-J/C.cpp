#include <cstdio>
#include <algorithm>
using namespace std;
using LL = long long;
/** È«ÅÅÁÐ£¨±©Á¦£© **/
struct Player
{
	int a, r, c;
	bool operator<(const Player &A) const
	{ return r != A.r? r > A.r: c > A.c; }
} a[200003];
int b[200003];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		LL ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			b[i] = i;
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i].r);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i].c);
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++i)
			a[i].a = i;
		do
		{
			LL tot = 0;
			for(int i = 1; i <= n; ++i)
				if(a[i].a > b[i])
					tot += a[i].c;
				else if(a[i].a < b[i])
					tot -= a[i].c;
			ans = max(ans, tot);
		} while(next_permutation(b + 1, b + n + 1));
		printf("%lld\n", ans);
	}
	return 0;
}