#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100003;
int a[N], s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, L, R;
	cin >> n >> L >> R;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	int ans = -0x3f3f3f3f;
	for(int i = 1; i + L - 1 <= n; ++i)
		for(int j = i + L - 1; j <= min(n, i + R - 1); ++j)
			ans = max(ans, s[j] - s[i - 1]);
	cout << ans;
	return 0;
}