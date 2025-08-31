#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 203;
struct
{ int x, y, p; }
a[N];
LL f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y >> a[i].p;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			f[i][j] = ceil(1.0 * ((LL)abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y)) / a[i].p);
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				f[i][j] = min(f[i][j], max(f[i][k], f[k][j]));
	LL ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= n; ++i) {
		LL maxn = 0;
		for(int j = 1; j <= n; ++j)
			maxn = max(maxn, f[i][j]);
		ans = min(ans, maxn);
	}
	cout << ans << endl;
	return 0;
}