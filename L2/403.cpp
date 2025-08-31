#include <bits/stdc++.h>
using namespace std;

bool a[10003];

int main()
{
	int l, m;
	scanf("%d%d", &l, &m);
	for(int i = 1; i <= m; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		for(int j = u; j <= v; ++j)
			a[j] = true;
	}
	int ans = 0;
	for(int i = 0; i <= l; ++i)
		if(!a[i])
			++ans;
	printf("%d", ans);
	return 0;
}