#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
int f[2][N][30], fa[N], a[N];

int fnd(int x) {
	if(fa[x] == x)
		return x;
	int fx = fa[x];
	fa[x] = fnd(fa[x]);
	a[x] ^= a[fx];
	return fa[x] = fa[fx];
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	iota(fa + 1, fa + n + 1, 1);
	for(int x, y, z; m--; ) {
		cin >> x >> y >> z;
		int u = fnd(x), v = fnd(y);
		if(u != v)
		{ a[v] = a[x] ^ a[y] ^ z; fa[v] = u; }
		else if((a[x] ^ a[y]) != z) {
			cout << "-1" << endl;
			return 0;
		}
	}
	for(int i = 1, j; i <= n; ++i) {
		j = fnd(i);
		for(int k = 0; k < 30; ++k)
			++f[a[i] >> k & 1][j][k];
	}
	for(int i = 1; i <= n; ++i)
		if(fa[i] == i)
			for(int j = 0; j < 30; ++j)
				if(f[0][i][j] < f[1][i][j])
					a[i] |= (1 << j);
	for(int i = 1; i <= n; ++i)
		cout << (fa[i] == i? a[i]: a[i] ^ a[fa[i]]) << ' ';
	cout << endl;
	return 0;
}
