#include <cstdio>
using namespace std;

int a[8003], b[8003];

int main()
{
	int n, Q;
	scanf("%d%d", &n, &Q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= i; ++j)
			if(i == j || a[j] <= a[i])
				++b[i];
			else
				++b[j];
	while(Q--)
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
					++b[i];
					--b[x];
				}
				else if((a[i] > a[x] || (a[i] == a[x] && i > x)) && (a[i] < v || (a[i] == v && i < x)))
				{
					--b[i];
					++b[x];
				}
			}
			a[x] = v;
		}
		else
			printf("%d\n", b[x]);
	}
	return 0;
}