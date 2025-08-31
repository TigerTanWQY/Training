#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1003;
int a[N][N];
long long f[2][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int h, w, c;
	cin >> h >> w >> c;
	for(int i = 0; i <= w + 1; ++i)
		f[0][i] = f[1][i] = 0x3f3f3f3f;
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= h; ++i) {
		for(int j = 1; j <= w; ++j) {
			cin >> a[i][j];
			ans = min(ans, min(f[0][j], f[0][j - 1]) + c + a[i][j]);
			f[0][j] = min(1LL * a[i][j], min(f[0][j], f[0][j - 1]) + c);
		}
		for(int j = w; j; --j) {
			ans = min(ans, min(f[1][j], f[1][j + 1]) + c + a[i][j]);
			f[1][j] = min(1LL * a[i][j], min(f[1][j], f[1][j + 1]) + c);
		}
	}
	cout << ans;
	return 0;
}