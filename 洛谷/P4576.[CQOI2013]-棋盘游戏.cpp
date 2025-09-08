#include <bits/stdc++.h>
using namespace std;

constexpr const int fx[]{0, -1, 1, 0, 0}, fy[]{0, 0, 0, -1, 1}, fx1[]{0, -1, 1, 0, 0, -2, 2, 0, 0}, fy1[]{0, 0, 0, -1, 1, 0, 0, -2, 2};
constexpr const int INF = 0x3f3f3f3f, N = 23;
int f[2][N * 3][N][N][N][N], n;

int dfs(int p, int cnt, int x1, int y1, int x2, int y2) {
	int res;
	if(cnt >= 3 * n)
		return INF;
	if(f[p][cnt][x1][y1][x2][y2])
		return f[p][cnt][x1][y1][x2][y2];
	if(x1 == x2 && y1 == y2)
		if(p == 0)
			return 0;
		else
			return INF;
	if(p == 0) {
		res = 0;
		for(int i = 1; i <= 4; ++i)
			if(x1 + fx[i] >= 1 && x1 + fx[i] <= n && y1 + fy[i] >= 1 && y1 + fy[i] <= n)
				res = max(res, dfs(1, cnt + 1, x1 + fx[i], y1 + fy[i], x2, y2));
	} else {
		res = INF;
		for(int i = 1; i <= 8; ++i)
			if(x2 + fx1[i] >= 1 && x2 + fx1[i] <= n && y2 + fy1[i] >= 1 && y2 + fy1[i] <= n)
				res = min(res, dfs(0, cnt + 1, x1, y1, x2 + fx1[i], y2 + fy1[i]));
	}
	return f[p][cnt][x1][y1][x2][y2] = ++res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	for(int i = 1; i <= 4; ++i)
		if(x1 + fx[i] == x2 && y1 + fy[i] == y2) {
			cout << "WHITE 1" << endl;
			return 0;
		}
	cout << "BLACK " << dfs(0, 0, x1, y1, x2, y2) << endl;
	return 0;
}
