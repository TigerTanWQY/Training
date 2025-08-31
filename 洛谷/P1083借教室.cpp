#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000003;
int r[N], d[N], s[N], t[N], n;
long long c[N], f[N];

inline bool check(const int &x)
{
	memset(c, 0, sizeof(c));
	for(int i = 1; i <= x; ++i)
	{
		c[s[i]] += d[i];
		c[t[i] + 1] -= d[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		f[i] = f[i - 1] + c[i];
		if(f[i] > r[i])
			return false;
	}
	return true;
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &r[i]);
	for(int i = 1; i <= m; ++i)
		scanf("%d%d%d", &d[i], &s[i], &t[i]);
	if(check(m))
	{
		printf("0");
		return 0;
	}
	int L = 1, R = m;
	while(L < R)
	{
		int M = (L + R) >> 1;
		if(check(M))
			L = M + 1;
		else
			R = M;
	}
	printf("-1\n%d", L);
	return 0;
}