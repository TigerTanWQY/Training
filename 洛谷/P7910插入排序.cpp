#include <cstdio>
using namespace std;

int a[8003], idx[8003];

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= i; ++j)
			if(i == j || a[j] < a[i] || a[j] == a[i])
				++idx[i];
			else
				++idx[j];
	while(q--)
	{
		int op, x;
		scanf("%d%d", &op, &x);
		if(op == 1)
		{
			int v;
			scanf("%d", &v);
			for(int i = 1; i <= n; ++i)
			{
				if(i == x)
					continue;
				if((a[i] < a[x] || (a[i] == a[x] && i < x)) && (a[i] > v || (a[i] == v && i > x)))
				{
					++idx[i];
					--idx[x];
				}
				else if((a[i] > a[x] || (a[i] == a[x] && i > x)) && (a[i] < v || (a[i] == v && i < x)))
				{
					--idx[i];
					++idx[x];
				}
			}
			a[x] = v;
		}
		else/* if(op == 2)*/
			printf("%d\n", idx[x]);
	}
	return 0;
}