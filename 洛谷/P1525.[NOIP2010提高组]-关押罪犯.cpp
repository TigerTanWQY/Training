#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 20003, M = 100003;
struct Crime {
	int u, v, w;
	bool operator>(const Crime& x) const
	{ return w > x.w; }
} a[M];
int fa[N], sz[N], c[N];

void init(int n) {
	for(int i = 1; i <= n; ++i)
	{ fa[i] = i; sz[i] = 1; }
}

int fnd(int x)
{ return fa[x] == x? x: fa[x] = fnd(fa[x]); }

void mrge(int x, int y) {
	x = fnd(x); y = fnd(y);
	if(x == y)
		return;
	if(sz[x] > sz[y])
		swap(x, y);
	fa[y] = x;
	sz[x] += sz[y];
}

bool same(int x, int y)
{ return fnd(x) == fnd(y); }

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	init(n);
	for(int i = 1; i <= m; ++i)
		cin >> a[i].u >> a[i].v >> a[i].w;
	sort(a + 1, a + m + 1, greater<>());
	for(int i = 1; i <= m + 1; ++i)
		if(same(a[i].u, a[i].v)) {
			cout << a[i].w;
			break;
		} else {
			if(!c[a[i].u])
				c[a[i].u] = a[i].v;
			else
				mrge(c[a[i].u], a[i].v);
			if(!c[a[i].v])
				c[a[i].v] = a[i].u;
			else
				mrge(a[i].u, c[a[i].v]);
		}
	cout << endl; return 0;
}
