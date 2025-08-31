#include <iostream>
#include <atcoder/modint>
using namespace std;
using LL = long long;
using mint = atcoder::modint1000000007;

mint f[63];
LL a[300'003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		LL x;
		cin >> x;
		int j = 0;
		for(; x; x >>= 1)
			f[++j] += x & 1;
	}
	mint j = 1, ans = 0;
	for(int i = 1; i <= 60; ++i, j *= 2)
		ans += f[i] * (n - f[i]) * j;
	cout << ans.val();
	cout.flush();
	return 0;
}