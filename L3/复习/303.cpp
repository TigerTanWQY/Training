#include <cstdio>
#include <algorithm>
using namespace std;

int fa[1003], a[1003], b[1003];

int main()
{
	int n, m;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		fa[v] = u;
	}
	scanf("%d", &m);
	while(m--)
	{
		int u, v, la = 0, lb = 0, x = 0;
		scanf("%d%d", &u, &v);
		for(; u != 1; u = fa[u])
			a[++la] = u;
		a[++la] = 1;
		for(int i = 1, j = la; i < j; ++i, --j)
			swap(a[i], a[j]);
		for(; v != 1; v = fa[v])
			b[++lb] = v;
		b[++lb] = 1;
		for(int i = 1, j = lb; i < j; ++i, --j)
			swap(b[i], b[j]);
		for(int i = 1; i <= la && i <= lb; ++i)
			if(a[i] == b[i])
				x = a[i];
			else
				break;
		printf("%d\n", x);
	}
	return 0;
}