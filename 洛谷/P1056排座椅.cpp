#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1003;
int h[N], s[N], p[N];

int main()
{
	int m, n, k, l, d;
	scanf("%d%d%d%d%d", &m, &n, &k, &l, &d);
	for(int i = 1; i <= d; ++i)
	{
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b);
		if(x == a)
			++s[min(y, b)];
		else
			++h[min(x, a)];
	}
	for(int i = 1; i <= m; ++i)
		p[i] = i;
	for(int i = 1; i < m; ++i)
		for(int j = 1; j <= m - i; ++j)
			if(h[j] < h[j + 1])
			{
				swap(h[j], h[j + 1]);
				swap(p[j], p[j + 1]);
			}
	for(int i = 1; i <= k; ++i)
		for(int j = 1; j <= k - i; ++j)
			if(p[j] > p[j + 1])
				swap(p[j], p[j + 1]);
	for(int i = 1; i <= k; ++i)
		printf("%d ", p[i]);
	printf("\n");
	for(int i = 1; i <= n; ++i)
		p[i] = i;
	for(int i = 1; i < n; ++i)
		for(int j = 1; j <= n - i; ++j)
			if(s[j] < s[j + 1])
			{
				swap(s[j], s[j + 1]);
				swap(p[j], p[j + 1]);
			}
	for(int i = 1; i <= l; ++i)
		for(int j = 1; j <= l - i; ++j)
			if(p[j] > p[j + 1])
				swap(p[j], p[j + 1]);
	for(int i = 1; i <= l; ++i)
		printf("%d ", p[i]);
	return 0;
}