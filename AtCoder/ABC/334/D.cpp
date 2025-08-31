#include <cstdio>
#include <algorithm>
using namespace std;
using LL = long long;

int r[200003];
LL s[200003];

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &r[i]);
	sort(r + 1, r + n + 1);
	for(int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + r[i];
	while(q--)
	{
		LL x;
		scanf("%lld", &x);
		int L = 0, R = n + 1;
		while(L < R)
		{
			int M = (0LL + L + R) >> 1;
			if(s[M] > x)
				R = M;
			else
				L = M + 1;
		}
		printf("%d\n", L - 1);
	}
	return 0;
}
