#include <iostream>
#include <algorithm>
using namespace std;
//! 很显然你不需要知道它选了几个，只需要知道选的数量是奇数是偶数
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	long long f0 = 0, f1 = -2e9;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		auto t0 = f0;
		f0 = max(f0, f1 + x * 2);
		f1 = max(f1, t0 + x);
	}
	cout << max(f0, f1) << endl;
	return 0;
}