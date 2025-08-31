#include <iostream>
using namespace std;

const int N = 40003;
bool flag = false;
char c[N][N];
int h, w, sx, sy;

void dfs(const int& x, const int& y, const int& s) {
	if(x == sx && y == sy && s > 2) {
		flag = true;
		return;
	} if(x < 0 || x >= h || y < 0 || y >= w || c[x][y] == '#')
		return;
	c[x][y] = '#';
	dfs(x + 1, y, s + 1);
	dfs(x, y + 1, s + 1);
	dfs(x - 1, y, s + 1);
	dfs(x, y - 1, s + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> h >> w;
	for(int i = 0; i < h; ++i)
		for(int j = 0; j < w; ++j) {
			cin >> c[i][j];
			if(c[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	dfs(sx, sy, 0);
	if(flag)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}