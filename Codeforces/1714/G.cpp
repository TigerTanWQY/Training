#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n, p, x, y, z, w, h[200010], a[200010], b[200010], ans[200010];
struct node{
	int x, y, z, w, next;
}d[400010];

void add(int x, int y, int z, int w){
	d[++p].y = y, d[p].z = z, d[p].w = w, d[p].next = h[x], h[x] = p;
}

void dfs(int x, int fa, int dep){
	for (int i=h[x]; i; i=d[i].next){
		int y = d[i].y;
		if (y == fa) continue;
		b[dep] = b[dep-1] + d[i].w;
		a[dep] = a[dep-1] + d[i].z;
		ans[d[i].y] = upper_bound(b+1, b+dep+1, a[dep]) - b - 1;
		dfs(y, x, dep+1);
	}
}

signed main(){
	scanf ("%lld", &t);
	while (t --){
		scanf ("%lld", &n);
		for (int i=1; i<=p; i++)
			d[i].x = d[i].y = d[i].z = d[i].w = d[i].next = h[i] = a[i] = b[i] = ans[i] = 0;
		p = 0;
		for (int i=2; i<=n; i++){
			scanf ("%lld%lld%lld", &x, &z, &w);
			add(i, x, z, w); add(x, i, z, w);
		}
		dfs(1, 0, 1);
		for (int i=2; i<=n; i++)
			printf ("%lld ", ans[i]);
		puts ("");
	}
	return 0;
}
