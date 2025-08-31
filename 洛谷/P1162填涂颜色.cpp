#include <iostream>
using namespace std;

const int d[2][6]{{0, -1, 1, 0, 0}, {0, 0, 0, -1, 1}};
const int N = 33;
int a[N][N], b[N][N], n;

void dfs(const int& x, const int& y) {
	if(x < 0 || x > n + 1 || y < 0 || y > n + 1 || a[x][y] != 0)
		return;
	a[x][y] = 1;
	for(int i = 1; i <= 4; ++i)
		dfs(x + d[0][i], y + d[1][i]);
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			cin >> b[i][j];
			if(b[i][j])
				a[i][j] = 2;
		}
	dfs(0, 0);
	for(int i = 1; i <= n; cout << '\n', ++i)
		for(int j = 1; j <= n; ++j)
			if(!a[i][j])
				cout << "2 ";
			else
				cout << b[i][j] << ' ';
	return 0;
}