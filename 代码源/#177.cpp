#include <cstdio>
using namespace std;

const int N = 200003;
char a[N];
int l[N], r[N], b[N], c[N];

int main()
{
	int n, m = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%*c%c", &a[i]);
		if(a[i] != a[i - 1])
			b[++m] = i;
	}
	for(int i = 1; i <= n; ++i)
	{
		l[i] = i - 1;
		r[i] = i + 1;
	}
	for(int p; m; )
	{
		p = 0;
		for(int i = 1; i <= m; ++i)
		{
			printf("%d ", b[i]);
			if(a[r[b[i]]] == a[b[i]])
				c[++p] = r[b[i]];
			r[l[b[i]]] = r[b[i]];
			l[r[b[i]]] = l[b[i]];
		}
		printf("\n");
		m = 0;
		for(int i = 1; i <= p; ++i)
			if(a[l[c[i]]] != a[c[i] - 1])
				b[++m] = c[i];
	}
	return 0;
}