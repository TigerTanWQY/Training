#include <iostream>
using namespace std;

int c[1003][1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 1, x; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			cin >> x;
			c[i][j] += x;
			c[i][j + 1] -= x;
			c[i + 1][j] -= x;
			c[i + 1][j + 1] += x;
		}
	for(int x1, y1, x2, y2, x; q--; ) {
		cin >> x1 >> y1 >> x2 >> y2 >> x;
		c[x1][y1] += x;
		c[x1][y2 + 1] -= x;
		c[x2 + 1][y1] -= x;
		c[x2 + 1][y2 + 1] += x;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
			cout << c[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}