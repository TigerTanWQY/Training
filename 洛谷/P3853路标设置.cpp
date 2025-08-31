#include <cstdio>
#include <algorithm>
using namespace std;

int a[100003], l, n, k;

inline bool check(const int &x)
{
	int y = k, tot = 0;
	for(int i = 1; i < n; ++i)
	{
		if(y < 0)
			return false;
		if(a[i] - tot <= x)
			tot = a[i];
		else
		{
			tot += x;
			--i;
			--y;
		}
	}
	return true;
}

int main()
{
	scanf("%d%d%d", &l, &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int L = 0, R = l + 1;
	while(L + 1 < R)
	{
		int M = (L + R) >> 1;
		if(check(M))
			R = M;
		else
			L = M;
	}
	printf("%d", R);
	return 0;
}