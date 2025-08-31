#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 1e5 + 3;
long long s[N], t[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		s[i] = s[i - 1] + x;
		t[i] = min(t[i - 1], s[i]);
	}
	long long ans = -0x3f3f3f3f3f3f3f3f;
	for(int i = m; i <= n; ++i)
		ans = max(ans, s[i] - t[i - m]);
	cout << ans << endl;
	return 0;
}