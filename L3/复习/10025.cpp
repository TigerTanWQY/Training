#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int T = 1e5, N = T + 3;
int x[N], a[N];
long long f[5][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int _ = 0, t, pos, w; _ < n; ++_) {
		cin >> t >> pos >> w;
		x[t] = pos;
		a[t] = w;
	}
	for(int i = 1; i < 5; ++i)
		f[i][0] = -0x3f3f3f3f3f3f3f3f;
	for(int t = 1; t <= T; ++t) {
		for(int i = 0; i < 5; ++i) {
			f[i][t] = f[i][t - 1];
			if(i != 0)
				f[i][t] = max(f[i][t], f[i - 1][t - 1]);
			if(i != 4)
				f[i][t] = max(f[i][t], f[i + 1][t - 1]);
		}
		f[x[t]][t] += a[t];
	}
	long long ans = 0;
	for(int i = 0; i < 5; ++i)
		ans = max(ans, f[i][T]);
	cout << ans << endl;
	return 0;
}