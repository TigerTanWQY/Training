#include <bits/stdc++.h>
using namespace std;

int a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	long long ans = a[1];
	for(int i = 2; i <= n; ++i) {
		ans *= a[i] - i + 1;
		ans %= (int) (1e9 + 7);
	}
	cout << ans << endl;
	return 0;
}
