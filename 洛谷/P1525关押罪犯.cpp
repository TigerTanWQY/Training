#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const int N = 20003;
const int M = 100003;
struct Crime {
	int u, v, w;
	bool operator>(const Crime& x) const
	{ return w > x.w; }
} a[M];
int fa[N], sz[N], c[N];

void init(const int& n) {
	for(int i = 1; i <= n; ++i) {
		fa[i] = i;
		sz[i] = 1;
	}
}

int fnd(const int& x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void mrge(const int& x, const int& y) {
	int fx = fnd(x), fy = fnd(y);
	if(fx != fy) {
		if(sz[fx] > sz[fy])
			swap(fx, fy);
		fa[fx] = fy;
		sz[fx] += sz[fy];
	}
}

bool same(const int& x, const int& y)
{ return fnd(x) == fnd(y); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
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
	return 0;
}