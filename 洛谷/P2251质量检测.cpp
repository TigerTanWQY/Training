#include <cstdio>
using namespace std;

int a[1000003], q[1000003], f = 1, r = 0;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i)
	{
		if(i - m + 1 > q[f])
			++f;
		while(r >= f && a[i] <= a[q[r]])
			--r;
		q[++r] = i;
		if(i + 1 >= m)
			printf("%d\n", a[q[f]]);
	}
	return 0;
}