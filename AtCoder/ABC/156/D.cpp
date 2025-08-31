#include <iostream>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint1000000007;

mint C(const int n, const int m) {
	mint ans = 1;
	for(int i = 1; i <= m; ++i)
		ans *= (n - m + i) * mint(i).inv();
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, a, b;
	cin >> n >> a >> b;
	cout << (mint(2).pow(n) - C(n, a) - C(n, b) - 1).val();
	cout.flush();
	return 0;
}