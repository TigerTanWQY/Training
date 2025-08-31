#include <iostream>
#include <cstring>
using namespace std;

int a[2][1003][1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	memset(a[0], 0x3f, sizeof(a[0]));
	for(int x, y, h, c; k--; ) {
		cin >> x >> y >> h >> c;
		if(h < a[0][x][y]) {
			a[0][x][y] = h;
			a[1][x][y] = c;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j)
			cout << a[1][i][j] << ' ';
		cout << '\n';
	}
	return 0;
}