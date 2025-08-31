#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
int a[N];
LL s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	LL tot = 0;
	for(int i = 1; i <= m; ++i)
		tot += (LL)a[i] * i;
	LL ans = tot;
	for(int i = m + 1; i <= n; ++i) {
		tot -= s[i - 1] - s[i - m - 1];
		tot += (LL)a[i] * m;
		ans = max(ans, tot);
	}
	cout << ans << endl;
	return 0;
}