#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int d[5][2]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {0, 0}};
constexpr const int N = 12 + 3;
int a[N][N], n, m, sx, sy;
LL k, ans;

void dfs(const int x, const int y, LL res, const int w) {
    res += a[x][y] + w - 1;
    if(w == k) {
		ans = max(ans, res);
		return;
	}
    LL tmp = a[x][y];
    a[x][y] = 0;
    for(LL i = 0; i < 5; ++i) {
        int tx = x + d[i][0], ty = y + d[i][1];
        if(tx < 1 || tx > n || ty < 1 || ty > m)
			continue;
        dfs(tx, ty, res, w + 1);
    }
    a[x][y] = tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> sx >> sy >> k;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    if(k < n * m)
        dfs(sx, sy, 0, 1);
    else {
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				ans += a[i][j];
		ans += n * m * (n * m - 1) / 2;
		k -= n * m;
		ans += k * n * m;
    }
    cout << ans << endl;
    return 0;
}