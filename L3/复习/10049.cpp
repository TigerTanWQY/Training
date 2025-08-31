#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> c;
bool flag = false;
int n, m, sx, sy;

void dfs(const int x, const int y, const int cnt) {
	if(x == sx && y == sy && cnt >= 4) {
		flag = true;
		return;
	} else if(x < 0 || x >= n || y < 0 || y >= m || c[x][y] == '#')
		return;
	c[x][y] = '#';
	dfs(x + 1, y, cnt + 1);
	dfs(x, y + 1, cnt + 1);
	dfs(x - 1, y, cnt + 1);
	dfs(x, y - 1, cnt + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	c.resize(n, vector<char>(m));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) {
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
	cout << endl;
	return 0;
}