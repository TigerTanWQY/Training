#include <cstdio>
#include <algorithm>
using namespace std;

int a[(1 << 20) + 3];

int bfind(const int &x, const int &L, const int &R)
{
	if(L == R)
		return 0;
	int mid = (L + R) >> 1, ret;
	if(mid < x)
		ret = bfind(x, mid + 1, R);
	else
		ret = bfind(x, L, mid);
	mid = (L + R + 1) >> 1;
	if(mid <= x)
		ret = min(ret, bfind(x, mid, R));
	else
		ret = min(ret, bfind(x, L, mid - 1));
	return ret + 1;
}

int main()
{
	int n, q;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &q);
	for(int x, i; q--; )
	{
		scanf("%d", &x);
		for(i = 0; i < n; ++i)
			if(a[i] == x)
				break;
		printf("%d\n", bfind(i, 0, n - 1));
	}
	return 0;
}