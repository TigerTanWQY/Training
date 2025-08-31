#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	long long ans = 0;
	for(int a = 1; a <= 10000; ++a)
		for(long long b = a; b <= n / a + 1; ++b) {
			long long k = n / a / b - b + 1;
			if(k <= 0)
				break;
			ans += k;
		}
	cout << ans;
	return 0;
}