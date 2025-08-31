#include <cstdio>
#include <algorithm>
using namespace std;

int a[203], f[203][203];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for(int len = 2; len < 2 * n; ++len)
		for(int L = len - 1; len - L < n && L; --L)
		{
			for(int k = L; k < len; ++k)
				f[L][len] = max(f[L][len], f[L][k] + f[k + 1][len] + a[L] * a[k + 1] * a[len + 1]);
			if(f[L][len] > ans)
				ans = f[L][len];
		}
	printf("%d", ans);
	return 0;
}