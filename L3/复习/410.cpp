#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

constexpr const int d[8][3]{{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
constexpr const int N = 1003;
vector<pair<int, int>> c;
bitset<N> vis[N];
int a[N][N], n;

void bfs(const int sx, const int sy) {
	queue<pair<int, int>> q;
	q.push({sx, sy});
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if(vis[x][y])
			continue;
		vis[x][y] = true;
		c.push_back({x, y});
		for(int i = 0; i < 8; ++i) {
			int tx = x + d[i][0], ty = y + d[i][1];
			if(1 <= tx && tx <= n && 1 <= ty && ty <= n && !vis[tx][ty] && a[tx][ty] == a[x][y])
				q.push({tx, ty});
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> a[i][j];
	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(!vis[i][j]) {
				c.clear();
				bfs(i, j);
				bool flag = true;
				for(const auto& [x, y]: c) {
					for(int l = 0; flag && l < 8; ++l) {
						int tx = x + d[l][0], ty = y + d[l][1];
						if(1 > tx || tx > n || 1 > ty || ty > n)
							continue;
						if(a[tx][ty] > a[x][y])
							flag = false;
					}
					if(!flag)
						break;
				}
				if(flag)
					++ans1;
				flag = true;
				for(const auto& [x, y]: c) {
					for(int l = 0; l < 8 && flag; ++l) {
						int tx = x + d[l][0], ty = y + d[l][1];
						if(1 > tx || tx > n || 1 > ty || ty > n)
							continue;
						if(a[tx][ty] < a[x][y])
							flag = false;
					}
					if(!flag)
						break;
				}
				if(flag)
					++ans2;
			}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}