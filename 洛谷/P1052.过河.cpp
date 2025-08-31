#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

constexpr const int N = 10'003;
bitset<N> flag;
int a[N], f[N], g[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, s, t, m;
	cin >> n >> s >> t >> m;
	if(s == t) {
		int ans = 0;
		for(int i = 1, x; i <= m; ++i) {
			cin >> x;
			ans += !(x % s);
		}
		cout << ans << endl;
		return 0;
	}
	for(int i = 1; i <= m; ++i)
		cin >> a[i];
	sort(a + 1, a + m + 1);
	g[m + 1] = min(n - a[m], 100);
	n = 0;
	for(int i = 1; i <= m; ++i)
		flag[n += (g[i] = min(a[i] - a[i - 1], 90))] = true;
	n += g[m + 1];
	for(int i = 1; i < n + 10; ++i) {
		f[i] = 0x3f3f3f3f;
		for(int j = s; j <= t; ++j)
			if(i >= j)
				f[i] = min(f[i], f[i - j] + flag[i]);
	}
	cout << *min_element(f + n + 1, f + n + 10) << endl;
	return 0;
}