#include <cstdio>
#include <algorithm>
using namespace std;

int a[100003], n, m;

inline bool check(const int &x)
{
	int tot = 0, num = 0;
	for(int i = 1; i <= n; ++i)
		if(tot + a[i] <= x)
			tot += a[i];
		else
		{
			tot = a[i];
			++num;
		}
	return num >= m;
}

int main()
{
	int L = 0, R = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		L = max(L, a[i]);
		R += a[i];
	}
	while(L <= R)
	{
		int M = (L + R) >> 1;
		if(check(M))
			L = M + 1;
		else
			R = M - 1;
	}
	printf("%d", L);
	return 0;
}