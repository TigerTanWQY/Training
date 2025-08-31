#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1003;
int fa[N], sz[N];

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
	int n;
	cin >> n;
	for(int m; n; ) {
		cin >> m;
		init(n);
		for(int u, v; m--; ) {
			cin >> u >> v;
			mrge(u, v);
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			if(fnd(i) == i)
				++ans;
		cout << ans - 1 << '\n';
		cin >> n;
	}
	return 0;
}