#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

const int d[2][4]{{0, -1, 1, 0}, {-1, 0, 0, 1}};
const int N = 1003;
vector<pair<int, int>> s;
string a[N];
bool vis[N][N];
int n, m;

void dfs(const int& x, const int& y) {
	s.push_back({x, y});
	for(int k = 0; k < 4; ++k) {
		int tx = x + d[0][k], ty = y + d[1][k];
		if(1 <= tx && tx <= n && 1 <= ty && ty <= m && a[tx][ty] == '#')
			return;
	}
	for(int k = 0; k < 4; ++k) {
		int tx = x + d[0][k], ty = y + d[1][k];
		if(1 <= tx && tx <= n && 1 <= ty && ty <= m && !vis[tx][ty] && a[tx][ty] == '.') {
			vis[tx][ty] = true;
			dfs(tx, ty);
			vis[tx][ty] = false;
		}
	}
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
				sort(s.begin(), s.end());
				s.erase(unique(s.begin(), s.end()), s.cend());
				ans = max(ans, int(s.size()));
				s.clear();
			}
	cout << ans;
	return 0;
}