#include <iostream>
#include <algorithm>
using namespace std;

const int P = 1e8;
int a[300003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		ans += a[i] * (n - 1LL);
	}
	sort(a + 1, a + n + 1);
	int t = n;
	for(int i = 1; i <= n; ++i) {
		for(; t > i && 0LL + a[t] + a[i] >= P; --t);
		ans -= 1LL * (n - (t = max(t, i))) * P;
	}
	cout << ans;
	return 0;
}