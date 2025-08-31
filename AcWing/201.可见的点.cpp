#include <iostream>
using namespace std;

int phi(int x) {
	int res = x;
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0) {
			res /= i;
			res *= i - 1;
			for(; x % i == 0; x /= i);
		}
	if(x != 1) {
		res /= x;
		res *= x - 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int i = 1, n; i <= T; ++i) {
		cin >> n;
		long long res = 1;
		for(int j = 1; j <= n; ++j)
			res += phi(j) * 2;
		cout << i << ' ' << n << ' ' << res << '\n';
	}
	cout.flush();
	return 0;
}