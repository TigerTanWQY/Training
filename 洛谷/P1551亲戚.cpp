#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100003;
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
		sz[fy] += sz[fx];
	}
}

bool same(const int& x, const int& y)
{ return fnd(x) == fnd(y); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, p;
	cin >> n >> m >> p;
	init(n);
	for(int x, y; m--; ) {
		cin >> x >> y;
		mrge(x, y);
	}
	for(int x, y; p--; ) {
		cin >> x >> y;
		if(same(x, y))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}