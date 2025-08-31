#include <cstdio>
using namespace std;

int a[48]{1, 1};

int main()
{
	for(int i = 2; i <= 45; ++i)
		a[i] = a[i - 1] + a[i - 2];
	int n;
	scanf("%d", &n);
	int top = n;
	for(int m = n; m; )
	{
		int k = 1;
		while(a[k] < m - a[k])
		{
			++k;
			--top;
		}
		m -= a[k];
		printf("%d ", a[k]);
	}
	return 0;
}