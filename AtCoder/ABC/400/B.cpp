#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL qpow(LL a, int b) {
	LL res = 1;
	for(; b; a *= a, b >>= 1) {
		if(b & 1)
			res *= a;
		if(a > 1e9) {
			res = -1;
			break;
		}
	}
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	LL ans = 0;
	for(int i = 0; i <= m; ++i) {
		auto x = qpow(n, i);
		if(x == -1) {
			cout << "inf" << endl;
			return 0;
		}
		ans += x;
		if(ans > 1e9) {
			cout << "inf" << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}
