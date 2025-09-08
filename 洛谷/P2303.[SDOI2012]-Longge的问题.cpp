#include <iostream>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL n;
	cin >> n;
	LL ans = n;
	for(LL i = 2; i * i <= n; ++i)
		if(n % i == 0) {
			int b = 0;
			for(; n % i == 0; n /= i)
				++b;
			ans /= i;
			ans *= b * i - b + i;
		}
	if(n > 1) {
		ans /= n;
		ans *= n + n - 1;
	}
	cout << ans << endl;
	return 0;
}
