#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 300'003;
int a[N], w[N];
LL s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		w[a[i]] = i;
	}
	for(int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + n - w[i] + 1;
	for(LL k; q--; cout.put('\n')) {
		cin >> k;
		int L = lower_bound(s, s + n + 1, k) - s;
		cout << w[L] << ' ' << k - s[L - 1] + w[L] - 1;
	}
	cout.flush();
	return 0;
}