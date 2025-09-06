#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using i128 = __int128_t;

constexpr const LL P = 998244353;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	LL n;
	cin >> n;
	if(n < 3) {
		cout.put('0') << endl;
		return 0;
	}
	LL ans = 0;
	for(LL b = 2; b <= n - 1; ) {
		LL t0 = (n - 1) / b, k0 = (n + 1) / b - 1,
			R1 = (t0 == 0) ? n : ((n - 1) / t0),
			R2 = (k0 + 1 == 0) ? n : ((n + 1) / (k0 + 1)),
			R = min({R1, R2, n - 1}), len = R - b + 1;
		i128 T_val = ((i128)t0 - k0) * (t0 + k0 + 1) / 2,
			A = (i128)k0 - T_val,
			B = ((i128)t0 - k0) * n - k0,
			sum_b = (i128) (b + R) * len / 2,
			total = A * sum_b + B * (i128)len;
		ans = (ans + total % P) % P;
		b = R + 1;
	}
	cout << ans << endl;
	return 0;
}
