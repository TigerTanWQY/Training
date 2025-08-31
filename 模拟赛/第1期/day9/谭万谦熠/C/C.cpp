#include <cstdio>
using namespace std;

long long a[100003];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int L, R, k, tot = 0;
		scanf("%d%d%d", &L, &R, &k);
		bool flag = true;
		for(int i = 1; i <= R - L + 1; ++i)
		{
			long long x = (2LL * L + i - 1) * i / 2, y = (2LL * R - i + 1) * i / 2, s = y / k * k;
			if(x <= s && s <= y)
			{
				flag = false;
				printf("%d\n", i);
				for(int j = 1; j <= i; ++j)
					a[++tot] = L + j - 1 + (s - x) / i;
				for(int j = tot, tmp = (s - x) % i; j >= 1 && tmp >= 1; --j, --tmp)
					++a[j];
				for(int j = 1; j <= tot; ++j)
					printf("%lld ", a[j]);
				break;
			}
		}
		if(flag)
			printf("-1");
		printf("\n");
	}
	return 0;
}