#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 1003;
int a[N][N], n, m, C;
LL f[N][N];

LL func() {
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			f[i][j] = min({a[i][j] - 1LL * C * i - 1LL * C * j, f[i - 1][j], f[i][j - 1]});
	LL res = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			res = min(res, a[i][j] + 1LL * C * i + 1LL * C * j + min(f[i - 1][j], f[i][j - 1]));
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> C;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	LL ans = func();
	for(int i = 1; i <= n; ++i)
		reverse(a[i] + 1, a[i] + m + 1);
	ans = min(ans, func());
	cout << ans;
	cout << endl;
	return 0;
}