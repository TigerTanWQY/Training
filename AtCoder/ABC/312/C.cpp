#include <cstdio>
using namespace std;

int a[200003], b[200003], n, m;

bool check(const int &x)
{
	int cnta = 0, cntb = 0;
	for(int i = 1; i <= n; ++i)
		if(x >= a[i])
			++cnta;
	for(int i = 1; i <= m; ++i)
		if(x <= b[i])
			++cntb;
	return cnta >= cntb;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &b[i]);
	int L = 0, R = 1e9 + 1;
	while(L < R)
	{
		int M = (0LL + L + R) >> 1;
		if(check(M))
			R = M;
		else
			L = M + 1;
	}
	printf("%d", L);
	return 0;
}