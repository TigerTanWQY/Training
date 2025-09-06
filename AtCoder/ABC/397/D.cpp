#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using i128 = __int128;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	LL N;
	cin >> N;
	LL max_d = 0, L = 1, R = 2e6;
	while(L <= R) {
		LL M = L + (R - L) / 2;
		i128 mid_cubed = (i128)M * M * M;
		if (mid_cubed <= 4 * (i128)N) {
			max_d = M;
			L = M + 1;
		} else
			R = M - 1;
	}
	for(LL d = 1; d <= max_d; ++d) {
		i128 d_cubed = (i128)d * d * d;
		if(d_cubed > 4 * (i128)N)
			continue;
		i128 A = 4 * (i128)N - d_cubed;
		if(A < 0)
			continue;
		i128 D = 3 * d * A;
		if (D < 0)
			continue;
		LL k = sqrtl(D);
		if ((i128)k * k != D)
			continue;
		LL numerator = k - 3 * d * d;
		if (numerator <= 0)
			continue;
		if (numerator % (6 * d) != 0)
			continue;
		LL y = numerator / (6 * d), x = y + d;
		i128 val = 3 * (i128)d * y * y + 3 * (i128)d * d * y + d_cubed;
		if (val == N) {
			cout << x << ' ' << y << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}
