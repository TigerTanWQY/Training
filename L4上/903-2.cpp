#include <iostream>
using namespace std;

const int N = 1003;
int a[3][N], fa[N], sz[N];

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
	int _;
	cin >> _;
	for(int xe, ye, n; _--; ) {
		cin >> xe >> ye >> n;
		init(n);
		for(int i = 1; i <= n; ++i)
			cin >> a[0][i] >> a[1][i] >> a[2][i];
		a[0][0] = a[1][0] = 0;
		a[2][0] = 1;
		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j <= n; ++j)
				if(1LL * (a[0][i] - a[0][j]) * (a[0][i] - a[0][j]) + 1LL * (a[1][i] - a[1][j]) * (a[1][i] - a[1][j]) <= 1LL * (a[2][i] + a[2][j]) * (a[2][i] + a[2][j]))
					mrge(i, j);
		int idx = -1;
		for(int i = 0; i <= n; ++i)
			if(1LL * (a[0][i] - xe) * (a[0][i] - xe) + 1LL * (a[1][i] - ye) * (a[1][i] - ye) <= 1LL * a[2][i] * a[2][i])
				idx = i;
		if(idx != -1 && same(0, idx))
			cout << '1';
		else
			cout << '0';
		cout << '\n';
	}
	return 0;
}