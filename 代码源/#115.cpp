#include <cstdio>
#include <algorithm>
using namespace std;

int a[50004], n;

bool check(const int &x)
{
	int cnt = 0, tot = 0;
	for(int i = 1; i <= n; ++i)
		if(a[i] % 2)
			++cnt;
	if(!cnt)
		cnt = 1;
	for(int i = 1; i <= n; ++i)
		tot += a[i] / 2;
	return tot / cnt * 2 >= x;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int tot = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", &a[i]);
			tot += a[i];
		}
		int L = 0, R = tot;
		while(L + 1 < R)
		{
			int M = (L + R) >> 1;
			if(check(M))
				L = M;
			else
				R = M;
		}
		printf("%d\n", R);
	}
	return 0;
}