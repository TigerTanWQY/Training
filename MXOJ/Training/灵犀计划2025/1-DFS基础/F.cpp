#include <bits/stdc++.h>
using namespace std;

constexpr const int d[][2]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
int n, m, a[8][8], vis[8][8], res, ans;

void dfs(int x, int y) {
	if(y == m + 1){
		dfs(x + 1, 1);
		return;
	}
	if(x == n + 1) {
		ans = max(res, ans);
		return;
	}
	dfs(x, y + 1);
	if(!vis[x][y]) {
		res += a[x][y];
		for(int i = 0; i < 8; ++i)
			++vis[x + d[i][0]][y + d[i][1]];
		dfs(x, y + 1);
		for(int i = 0; i < 8; ++i)
			--vis[x + d[i][0]][y + d[i][1]];
		res -= a[x][y];
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	while(_T--) {
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				cin >> a[i][j];
		ans = 0;
		dfs(1, 1);
		cout << ans << '\n';
	}
	cout.flush(); return 0;
}
