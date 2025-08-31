#include <cstdio>
using namespace std;

int d[50003], n, m;

bool check(const int &x)
{
	int tot = 0;
	for(int i = 0, now = 0; i <= n; )
	{
		++i;
		if(d[i] - d[now] < x)
			++tot;
		else
			now = i;
	}
	return tot <= m;
}

int main()
{
	int l;
	scanf("%d%d%d", &l, &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &d[i]);
	d[n + 1] = l;
	int L = 1, R = l, ans;
	while(L <= R)
	{
		int M = (L + R) >> 1;
		if(check(M))
		{
			ans = M;
			L = M + 1;
		}
		else
			R = M - 1;
	}
	printf("%d", ans);
	return 0;
}