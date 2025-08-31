#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr const int N = 3003;
int a[N], f[N][N][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(f, 0x3f, sizeof(f));
	f[0][0][1] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= m; ++j) {
			f[i][j][0] = min(f[i - 1][j][1] + 1, f[i - 1][j][0]);
			if(j >= a[i])
				f[i][j][1] = min(f[i - 1][j - a[i]][0], f[i - 1][j - a[i]][1]);
		}
	for(int i = 1; i <= m; cout.put('\n'), ++i) {
		int ans = min(f[n][i][1], f[n][i][0]);
		if(ans > n)
			ans = -1;
		cout << ans;
	}
	cout.flush();
	return 0;
}