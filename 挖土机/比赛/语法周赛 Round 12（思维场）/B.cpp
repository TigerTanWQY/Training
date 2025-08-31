#include <iostream>
using namespace std;
using LL = long long;

int func(LL x) {
	int res = 0;
	for(; x; x /= 10)
		res += x % 10;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	LL n;
	cin >> n;
	LL ans = 0;
	for(LL i = 1; i <= n; ++i) {
		LL x = i;
		for(; x >= 10; x = func(x));
		ans += x;
	}
	cout << ans;
	return 0;
}