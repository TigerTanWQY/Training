#include <iostream>
using namespace std;

constexpr const int N = 50003;
int a[N], b[N], c[N], d[N], x[N], cnt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> x[i];
		++cnt[x[i]];
	}
	for(int t = 1; t * 9 < n; ++t) {
		int tot = 0;
		for(int D = 9 * t + 2; D <= n; ++D) {
			const int A = D - 9 * t - 1, B = A + 2 * t, C = D - t;
			tot += cnt[A] * cnt[B];
			c[C] += cnt[D] * tot;
			d[D] += cnt[C] * tot;
		}
		tot = 0;
		for(int A = n - 9 * t - 1; A; --A) {
			const int B = A + 2 * t, C = B + 6 * t + 1, D = A + 9 * t + 1;
			tot += cnt[C] * cnt[D];
			a[A] += cnt[B] * tot;
			b[B] += cnt[A] * tot;
		}
	}
	for(int i = 1; i <= m; ++i)
		cout << a[x[i]] << ' ' << b[x[i]] << ' ' << c[x[i]] << ' ' << d[x[i]] << '\n';
	cout.flush();
	return 0;
}