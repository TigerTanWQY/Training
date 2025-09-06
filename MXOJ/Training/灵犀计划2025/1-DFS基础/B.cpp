#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 17;
const string c[]{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"};
constexpr const int d[4][2]{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
bool vis[N][N], flg = false;
int a[N][N], ex, ey;

void dfs(int x, int y, string ans){
	if(x == ex && y == ey) {
		cout << ans << endl;
		flg = true;
	}
	for(int i = 0; i < 4; ++i) {
		int tx = x + d[i][0], ty = y + d[i][1];
		if(a[tx][ty] == 1 && !vis[tx][ty]) {
			vis[tx][ty] = true;
			dfs(tx, ty, ans + "->" + "(" + c[tx] + "," + c[ty] + ")");
			vis[tx][ty] = false;
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, sx, sy;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	cin >> sx >> sy >> ex >> ey;
	vis[sx][sy] = true;
	dfs(sx, sy, "(" + c[sx] + "," + c[sy] + ")");
	if(!flg)
		cout << "-1" << endl;
	return 0;
}
/*
https://k2s.cc/file/f1eda70c3b634/T.V.12210.rar
https://k2s.cc/file/a7b43c9e666af/T.V.11013.rar
https://k2s.cc/file/f1eda70c3b634/T.V.11407.rar
*/
