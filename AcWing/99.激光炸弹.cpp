#include <bits/stdc++.h>
using namespace std;

constexpr const int n = 5005;
int s[n+7][n+7];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m, r;
	cin >> m >> r;
	int mxx = 0, mxy = 0;
	for(int x, y, w; m--; ) {
		cin >> x >> y >> w;
		++x; ++y;
		mxx = max(mxx, x);
		mxy = max(mxy, y);
		s[x][y] += w;
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			s[i][j] += s[i][j-1] + s[i-1][j] - s[i-1][j-1];
	if(r >= mxx && r >= mxy) {
		cout << s[n][n] << endl;
		return 0;
	}
	int ans = 0;
	for(int i = 1; i+r-1 <= n; ++i)
		for(int j = 1; j+r-1 <= n; ++j)
			ans = max(ans, s[i+r-1][j+r-1] - s[i-1][j+r-1] - s[i+r-1][j-1] + s[i-1][j-1]);
	cout << ans << endl;
	return 0;
}
