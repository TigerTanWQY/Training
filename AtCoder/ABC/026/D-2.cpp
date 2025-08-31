#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 1003;
string a[N];
bool vis[N][N];
int f[N][N], n, m;

void dfs(const int& x, const int& y) {
	if(1 < x && x < n && 1 < y && y < n && !vis[x][y] && a[x][y] == '.') {
		vis[x][y] = true;
		++f[x][y];
		dfs(x + 1, y);
		dfs(x - 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
	}
	vis[x][y] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		string t;
		cin >> t;
		a[i] = "$" + t;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(a[i][j] == '.') {
				dfs(i, j);
				ans = max(ans, f[i][j]);
			}
	cout << ans;
	return 0;
}