#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 250003;
int a[N], f[N], s1[N], s2[N], cnt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		++a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		if(a[i] - a[i - 1] >= 2 * m) {
			const int& c = a[i] - a[i - 1] - 2 * m;
			for(int j = i; j <= n; ++j)
				a[j] -= c;
		}
	const int T = a[n] + m;
	for(int i = 1; i <= n; ++i)
		++cnt[a[i]];
	for(int i = 1; i <= T; ++i) {
		s1[i] = s1[i - 1] + cnt[i];
		s2[i] = s2[i - 1] + cnt[i] * i;
	}
	int ans = 0x3f3f3f3f;
	for(int i = 1; i <= T; ++i) {
		f[i] = i * s1[i] - s2[i];
		for(int j = i - m; j >= 1 && j >= i - 2 * m + 1; --j)
			f[i] = min(f[i], f[j] + i * (s1[i] - s1[j]) - (s2[i] - s2[j]));
		if(i >= a[n])
			ans = min(ans, f[i]);
	}
	cout << ans << endl;
	return 0;
}