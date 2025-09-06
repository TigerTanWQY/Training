#include <bits/stdc++.h>
using namespace std;

constexpr const int dxy[4][2]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
constexpr const char op[] = ">v^<";
constexpr const int N = 1003;
char s[N][N], ans[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> q;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			cin >> s[i][j];
			if(s[i][j] == 'E') {
				q.push({i, j});
				ans[i][j] = 'E';
			} else if(s[i][j] == '#')
				ans[i][j] = '#';
		}
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i) {
			int tx = x + dxy[i][0], ty = y + dxy[i][1];
			if(1 <= tx && tx <= n && 1 <= ty && ty <= m && !ans[tx][ty]) {
				ans[tx][ty] = op[i];
				q.push({tx, ty});
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		cout << (ans[i] + 1) << '\n';
	cout.flush(); return 0;
}
