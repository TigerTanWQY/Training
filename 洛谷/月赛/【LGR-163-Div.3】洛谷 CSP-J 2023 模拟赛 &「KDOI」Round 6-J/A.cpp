#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
/** Ã¶¾Ù **/
int a[10], b[10];

inline int ceil(const int &x, const int &y)
{ return x / y + !!(x % y); }

int main()
{
	int n, t, tot = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &a[i], &b[i]);
		tot += 100 / a[i] * b[i];
	}
	scanf("%d", &t);
	if(tot >= t)
	{
		printf("Already Au.");
		return 0;
	}
	for(int i = 1; i <= n; ++i)
		if(ceil((t - tot), (100 / a[i])) <= a[i] - b[i])
			printf("%d\n", ceil((t - tot), (100 / a[i])));
		else
			printf("NaN\n");
	return 0;
}