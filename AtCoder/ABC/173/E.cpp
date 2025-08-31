#include <bits/stdc++.h>
using namespace std;

constexpr const int P = 1e9 + 7;
long long a[200003];
#include <atcoder/modint>
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	atcoder::modint1000000007 ans = 1;
	int R = n - 1, w = 1;
	if(k & 1) {
		w = (a[R] < 0? -1: 1);
		ans = a[R--]; --k;
	}
	for(int L = 0; k; k -= 2) {
		long long x = a[L] * a[L + 1], y = a[R] * a[R - 1];
		if(x * w > y * w) {
			ans *= x % P;
			L += 2;
		} else {
			ans *= y % P;
			R -= 2;
		}
	}
	cout << ans.val() << endl;
	return 0;
}
