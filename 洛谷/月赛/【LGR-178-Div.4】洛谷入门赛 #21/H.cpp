#include <iostream>
#include <cmath>
using namespace std;

int n, k;

bool check(int x) {
	int tot = 0;
	for(; x; x /= 10)
		tot += x % 10;
	return tot <= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	int maxn = pow(10, n), ans = 0;
	for(int i = 1; i < maxn; ++i)
		if(check(i)) {
			++ans;
//			cout << i << ' ';
		}
	cout << ans;
	return 0;
}