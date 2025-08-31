#include <cstdio>
#include <algorithm>
using namespace std;

int a[500003];

inline int __lcm(const int &x, const int &y)
{ return x * y / __gcd(x, y); }

int main()
{
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int op, n, x, cnt = 0;
		scanf("%d%d%d", &op, &n, &x);
		if(op == 1)
		{
			for(int i = 1; i <= n; ++i)
				a[i] = x / (n - 1);
			int r = x % (n - 1);
			for(int i = n; i >= 1 && r; --i, --r)
				++a[i];
			for(; cnt <= n; ++cnt)
			{
				int tot = 0;
				for(int i = 1; i < n; ++i)
					tot += __gcd(a[i], a[i + 1]);
				if(tot == x)
				{
					for(int i = 1; i <= n; ++i)
						printf("%d ", a[i]);
					printf("\n");
					break;
				}
				for(int i = 1; i <= n; ++i)
					if(__gcd(a[i], a[i + 1]) != x / (n - 1))
						if(a[i] > a[i + 1])
							++a[i + 1];
						else
							++a[i];
			}
			if(cnt > n)
				printf("-1\n");
		}
		else
		{
			for(int i = 1; i <= n; ++i)
				a[i] = x / (n - 1);
			int r = x % (n - 1);
			for(int i = n; i >= 1 && r; --i, --r)
				++a[i];
			for(; cnt <= n; ++cnt)
			{
				int tot = 0;
				for(int i = 1; i < n; ++i)
					tot += __lcm(a[i], a[i + 1]);
				if(tot == x)
				{
					for(int i = 1; i <= n; ++i)
						printf("%d ", a[i]);
					printf("\n");
					break;
				}
				for(int i = 1; i <= n; ++i)
					if(__lcm(a[i], a[i + 1]) != x / (n - 1))
						if(a[i] > a[i + 1])
							++a[i + 1];
						else
							++a[i];
			}
			if(cnt > n)
				printf("-1\n");
		}
	}
	return 0;
}