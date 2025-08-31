#include <bits/stdc++.h>
using namespace std;

struct Number
{ int v, pos; }
a[8003];
int ans[8003];

bool operator<(const Number& x, const Number& y)
{
	if(x.v != y.v)
		return x.v < y.v;
	else
		return x.pos < y.pos;
}

int main()
{
	int n, Q;
	scanf("%d%d", &n, &Q);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i].v);
		a[i].pos = i;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		ans[a[i].pos] = i;
	while(Q--)
	{
		int op, x;
		scanf("%d%d", &op, &x);
		if(op == 2)
			printf("%d\n", ans[x]);
		else
		{
			int v;
			scanf("%d", &v);
			int p = ans[x];
			a[p].v = v;
			for(int i = p; i < n; ++i)
				swap(a[i], a[i + 1]);
			for(int i = n; i >= 2; --i)
				if(a[i] < a[i - 1])
					swap(a[i], a[i - 1]);
				else
					break;
			for(int i = 1; i <= n; ++i)
				ans[a[i].pos] = i;
		}
	}
	return 0;
}