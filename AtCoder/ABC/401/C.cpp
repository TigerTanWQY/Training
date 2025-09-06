#include <bits/stdc++.h>
using namespace std;

constexpr const int P = 1e9;
int a[1000003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	long long tot = 0;
	for(int i = 0; i < k; ++i) {
		a[i] = 1;
		tot += a[i];
	}
	for(int i = k; i <= n; ++i) {
		a[i] = tot;
		tot += a[i];
		tot -= a[i - k];
		tot += P; tot %= P;
	}
	cout << a[n] << endl; return 0;
}
