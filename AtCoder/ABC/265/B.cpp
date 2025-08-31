#include <cstdio>
using namespace std;

int a[100003], b[100003];

int main()
{
	int n, m, i;
	long long t;
	scanf("%d%d%lld", &n, &m, &t);
	for(i = 1; i < n; ++i)
		scanf("%d", &a[i]);
	for(int x, y; m--; )
	{
		scanf("%d%d", &x, &y);
		b[x] = y;
	}
	for(i = 1; i < n; ++i)
	{
		if(t <= a[i])
		{
			printf("No");
			return 0;
		}
		t -= a[i];
		t += b[i + 1];
	}
	printf("Yes");
	return 0;
}
