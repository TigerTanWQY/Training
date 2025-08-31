#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.tie(NULL);
	int h, w, ans = INF;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	for(int i = 0; i < h; ++i)
		for(int j = 0; j < w; ++j)
			cin >> a[i][j];
	vector<vector<vector<int>>> dp(h, vector<vector<int>>(2, vector<int>(2, INF)));
	dp[0][0][0] = 0;
	dp[0][0][1] = 1;
	for(int i = 1; i < h; ++i)
		for(int j = 0; j < 2; ++j)
			for(int k = 0; k < 2; ++k)
				for(int l = 0; l < 2; ++l) {
					vector<int> x(w, -1), y = a[i - 1], z = a[i];
					if(i != 1)
						x = a[i - 2];
					if(j)
						for(int m = 0; m < w; ++m)
							x[m] = 1 - x[m];
					if(k)
						for(int m = 0; m < w; ++m)
							y[m] = 1 - y[m];
					if(l)
						for(int m = 0; m < w; ++m)
							z[m] = 1 - z[m];
					bool flag = true;
					for(int m = 0; m < w; ++m)
						if(x[m] != y[m] && y[m] != z[m] && (!m || y[m] != y[m - 1]) && (m == w - 1 || y[m] != y[m + 1]))
							flag = false;
					if(i == h - 1)
						for(int m = 0; m < w; ++m)
							if(z[m] != y[m] && (!m || z[m] != z[m - 1]) && (m == w - 1 || z[m] != z[m + 1]))
								flag = false;
					if(flag)
						dp[i][k][l] = min(dp[i][k][l], dp[i - 1][j][k] + l);
				}
	for(int j = 0; j < 2; ++j)
		for(int k = 0; k < 2; ++k)
			ans = min(ans, dp[h - 1][j][k]);
	if(ans == INF)
		cout << "-1";
	else
		cout << ans;
	return 0;
}