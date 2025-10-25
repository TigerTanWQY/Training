#include <bits/stdc++.h>
using namespace std;

int w[18], f[18], G[13][18];

void Print(int x, int y) {
	if(!x)
		return;
	Print(x-1, y-G[x][y]);
	cout << x << ' ' << G[x][y] << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j)
			cin >> w[j];
		for(int j = m; ~j; --j)
			for(int k = 1; k <= j; ++k)
				if(f[j-k] + w[k] > f[j]) {
					f[j] = f[j-k] + w[k];
					G[i][j] = k;
				}
	}
	cout << f[m] << '\n';
	Print(n, m);
	cout.flush(); return 0;
}
