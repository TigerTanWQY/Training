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
} e[M];
int fa[N], c[N];

void init(const int& n) {
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
}

int fnd(const int& x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void mrge(const int& x, const int& y) {
	int fx = fnd(x), fy = fnd(y);
	if(fx != fy)
		fa[fx] = fy;
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
		cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + m + 1, greater<>());
	for(int i = 1; i <= m + 1; ++i)
		if(same(e[i].u, e[i].v)) {
			cout << e[i].w;
			break;
		} else {
			if(!c[e[i].u])
				c[e[i].u] = e[i].v;
			else
				mrge(c[e[i].u], e[i].v);
			if(!c[e[i].v])
				c[e[i].v] = e[i].u;
			else
				mrge(e[i].u, c[e[i].v]);
		}
	return 0;
}