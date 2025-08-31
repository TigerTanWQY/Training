#include <iostream>
#include <cstring>
using namespace std;
using LL = long long;

constexpr const int M = 103, N = 10'003;
int a[M], b[N], n, m;
LL f[N * 2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 0; i < m; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	memset(f, -0x3f, sizeof(f));
	f[0] = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			f[i + a[j]] = max(f[i + a[j]], f[i] + b[i]);
	LL ans = -0x3f3f3f3f3f3f3f3f;
	for(int i = n; i < 2 * n; ++i)
		ans = max(ans, f[i]);
	cout << ans;
	cout.flush();
	return 0;
}