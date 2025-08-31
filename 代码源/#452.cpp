#include <cstdio>
using namespace std;

int a[1000003];

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	while(q--)
	{
		int op;
		scanf("%d", &op);
		if(op == 1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			a[x] = y;
		}
		else
		{
			int y;
			scanf("%d", &y);
			for(int i = 1; i <= n; ++i)
				if(a[i] < y)
					a[i] = y;
		}
	}
	for(int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}