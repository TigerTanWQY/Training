#include <iostream>
using namespace std;

const int N = 1003;
int a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		long long tot = -0x3f3f3f3f3f3f3f3f;
		for(int j = 1; j <= m; ++j)
			tot = max(tot, a[i][j] - 1LL * k * j);
		ans += tot;
	}
	cout << ans;
	return 0;
}