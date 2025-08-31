#include <iostream>
#include <cstring>
using namespace std;

constexpr const int N = 10'003;
int a[N], f[N][2'003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		int maxn = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			maxn = max(maxn, a[i]);
		}
		for(int i = 1; i <= n + 1; ++i)
			for(int L = 0; L <= 2 * maxn; ++L)
				f[i][L] = 0x3f3f3f3f;
		f[1][0] = 0;
		for(int i = 1; i <= n; ++i)
			for(int L = 0; L <= 2 * maxn; ++L)
				if(f[i][L] != 0x3f3f3f3f) {
					f[i + 1][max(0, L - a[i])] = min(f[i + 1][max(0, L - a[i])], f[i][L] + a[i]);
					if(L + a[i] <= 2 * maxn)
						f[i + 1][L + a[i]] = min(f[i + 1][L + a[i]], max(f[i][L] - a[i], 0));
				}
		int ans = 2 * maxn + 1;
		for(int L = 0; L <= 2 * maxn; ++L)
			ans = min(ans, L + f[n + 1][L]);
		cout << ans;
	}
	cout.flush();
	return 0;
}