#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int d[4][3]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
constexpr const int N = 103, M = 1003;
vector<pair<int, bool>> G[N * M * 4];
vector<int> c[M];
int a[N][N], dis[N * M * 4], n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m;
	memset(a, -1, sizeof(a));
	for(int x, y, b; m--; ) {
		cin >> x >> y >> b;
		a[x][y] = b;
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			for(int k = 0; k < 4; ++k) {
				const int x = i + d[k][0], y = j + d[k][1];
				if(1 > x || x > n || 1 > y || y > n)
					continue;
				const int s = (i - 1) * n + j, t = (x - 1) * n + y;
				if(~a[i][j])
					if(a[x][y] == a[i][j])
						G[a[i][j] * n * n + s].push_back({a[x][y] * n * n + t, 0});
					else if(~a[x][y])
						G[a[i][j] * n * n + s].push_back({a[x][y] * n * n + t, 1});
					else
						G[a[i][j] * n * n + s].push_back({(a[i][j] + 2) * n * n + t, 1});
				else if(~a[x][y]) {
					G[a[x][y] * n * n + s].push_back({a[x][y] * n * n + t, 0});
					G[(1 - a[x][y]) * n * n + s].push_back({a[x][y] * n * n + t, 1});
				}
			}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(!~a[i][j]) {
				const int s = (i - 1) * n + j;
				G[2 * n * n + s].push_back({s, 1});
				G[3 * n * n + s].push_back({n * n + s, 1});
			}
	memset(dis, -1, sizeof(dis));
	const int s = a[1][1] * n * n + 1;
	dis[s] = 0;
	c[0].push_back(s);
	for(int i = 0; ; ++i) {
		int f = 0, r = c[i].size() - 1;
		while(f <= r) {
			int x = c[i][f++];
			for(const auto &y: G[x])
				if(!y.second && dis[y.first] == -1) {
					dis[y.first] = i;
					c[i].push_back(y.first);
					++r;
				}
		}
		for(const auto &j: c[i])
			for(const auto &y: G[j])
				if(y.second && dis[y.first] == -1) {
					dis[y.first] = i + 1;
					c[i + 1].push_back(y.first);
				}
		if(c[i + 1].empty())
			break;
	}
	int ans = 0x3f3f3f3f;
	if(dis[n * n] != -1)
		ans = min(ans, dis[n * n]);
	if(dis[2 * n * n] != -1)
		ans = min(ans, dis[2 * n * n]);
	if(ans == 0x3f3f3f3f)
		ans = -1;
	cout << ans << endl;
	return 0;
}