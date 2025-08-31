#include <cstdio>
#include <algorithm>
using namespace std;

int a[10004], f[10004];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	a[++n] = 10001;
	for(int i = 1; i <= n; ++i)
	{
		f[i] = 1;
		for(int j = 1; j < i; ++j)
			if(a[j] <= a[i])
				f[i] = max(f[i], f[j] + 1);
	}
	printf("%d", f[n] - 1);
	return 0;
}