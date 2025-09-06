#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
int a[N], f[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i = 1, k; i <= n; ++i) {
		cin >> k;
		f[i] = max(f[i - 1], a[k] + 1);
		a[k] = i;
	}
	for(int L, R; q--; cout.put('\n')) {
		cin >> L >> R;
		cout << (f[R] <= L? "Yes": "No");
	}
	cout.put('\n'); return 0;
}
