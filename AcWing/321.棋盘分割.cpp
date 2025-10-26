#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 16;
int s[N][N], n, m = 8;
double f[N][N][N][N][N], X;

double get(int x1, int y1, int x2, int y2) {
	double dlt = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
	dlt = dlt - X;
	return dlt * dlt;
}
double dp(int k, int x1, int y1, int x2, int y2) {
	if(f[k][x1][y1][x2][y2] >= 0)
		return f[k][x1][y1][x2][y2];
	else if(k == n)
		return f[k][x1][y1][x2][y2] = get(x1, y1, x2, y2);
	double t = 1e9;
	for(int i = x1; i < x2; i ++)
		t = min({t, dp(k + 1, x1, y1, i, y2) + get(i + 1, y1, x2, y2),
				dp(k + 1, i + 1, y1, x2, y2) + get(x1, y1, i, y2)});
	for(int i = y1; i < y2; i ++) {
		t = min({t, dp(k + 1, x1, y1, x2, i) + get(x1, i + 1, x2, y2),
				dp(k + 1, x1, i + 1, x2, y2) + get(x1, y1, x2, i)});
	}
	return f[k][x1][y1][x2][y2] = t;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= m; i ++)
		for(int j = 1; j <= m; j ++)
			cin >> s[i][j];
	for(int i = 1; i <= m; i ++)
		for(int j = 1; j <= m; j ++)
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
	memset(f, -1, sizeof f);
	X = (double) s[m][m] / n;
	cout << fixed << setprecision(3) << sqrt(dp(1, 1, 1, m, m) / n) << endl;
	return 0;
}
