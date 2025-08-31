#include <iostream>
#include <utility>
#include <queue>
using namespace std;

const int d[2][4]{{0, -1, 1, 0}, {-1, 0, 0, 1}};
const int N = 503;
char a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, ans = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i] + 1;
	queue<pair<int, int>> q;
	if(a[1][1] != '*')
		q.push({1, 1});
	if(a[1][m] != '*')
		q.push({1, m});
	if(a[n][1] != '*')
		q.push({n, 1});
	if(a[n][m] != '*')
		q.push({n, m});
	while(!q.empty()) {
		auto x = q.front().first, y = q.front().second;
		q.pop();
		a[x][y] = '1';
		for(int k = 0; k < 4; ++k) {
			int tx = x + d[0][k], ty = y + d[1][k];
			if(1 <= tx && tx <= n && 1 <= ty && ty <= m && a[tx][ty] == '0') {
				a[tx][ty] = '1';
				q.push({tx, ty});
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(a[i][j] == '0')
				++ans;
	cout << ans;
	return 0;
}