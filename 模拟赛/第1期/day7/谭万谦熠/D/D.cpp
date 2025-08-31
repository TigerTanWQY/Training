#include <cstdio>
using namespace std;

bool b[10000003];
int c[664579 + 3], cnt = 0;
long long f[10000003];

inline int gcd(int x, int y)
{
	while(y)
	{
		int tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}

int main()
{
	for(int i = 2; i <= 1e7; ++i)
	{
		if(!b[i])
		{
			c[++cnt] = i;
			f[i] = i;
		}
		for(int j = 1; j <= cnt && i * c[j] <= 1e7; ++j)
		{
			b[i * c[j]] = true;
			f[i * c[j]] = f[i] + c[j];
			if(!(i % c[j]))
				break;
		}
	}
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int tmp = gcd(x, y);
		printf("%lld\n", f[x / tmp] + f[y / tmp]);
	}
	return 0;
}