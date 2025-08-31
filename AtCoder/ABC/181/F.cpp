#include <bits/stdc++.h>
using namespace std;
#define _x first
#define _y second

constexpr const int N = 303;
pair<double, double> a[N];
double f[N][N], ans;
int fa[N], n;

int fnd(int x) {
	if(x != fa[x])
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void mrge(int x, int y) {
	x = fnd(x); y = fnd(y);
	if(x == y)
		return;
	fa[y] = x;
}

bool chk(double x) {
	iota(fa + 1, fa + n * 3 + 1, 1);
	for(int i = 1; i <= n * 3; ++i)
		for(int j = 1; j <= n * 3; ++j)
			if(i != j && f[i][j] - x < 1e-8)
				mrge(i, j);
	for(int i = n + 1; i <= n * 2; ++i)
		for(int j = n * 2 + 1; j <= n * 3; ++j)
			if(fnd(i) == fnd(j))
				return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i = 0; i < N; ++i)
		fill(f[i], f[i] + N, 1e18);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i]._x >> a[i]._y;
		a[n + i] = {a[i]._x, -100};
		a[n * 2 + i] = {a[i]._x, 100};
	}
	for(int i = 1; i <= n * 3; ++i)
		for(int j = 1; j <= n * 3; ++j)
			f[i][j] = f[j][i] = sqrt((a[i]._x - a[j]._x) * (a[i]._x - a[j]._x) + (a[i]._y - a[j]._y) * (a[i]._y - a[j]._y));
	double L = 0, R = 200;
	for(int _ = 1000; _--; ) {
		double M = (R + L) / 2;
		if(chk(M))
			L = M;
		else
			R = M;
	}
	cout << fixed << setprecision(6) << L / 2 << endl;
	return 0;
}
