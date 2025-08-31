#include <iostream>
using namespace std;

constexpr const int dxy[4][3]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
constexpr const int N = 10 + 3;
bool vis[N][N];
char s[N][N];
int n, m, k, ans = 0;

void dfs(const int x, const int y, const int cnt) {
	if(cnt == k) {
		++ans;
		return;
	}
	vis[x][y] = true;
	for(int i = 0; i < 4; ++i) {
		const int tx = x + dxy[i][0], ty = y + dxy[i][1];
		if(1 <= tx && tx <= n && 1 <= ty && ty <= m && s[tx][ty] == '.' && !vis[tx][ty])
			dfs(tx, ty, cnt + 1);
	}
	vis[x][y] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i)
		cin >> (s[i] + 1);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(s[i][j] == '.')
				dfs(i, j, 0);
	cout << ans << endl;
	return 0;
}