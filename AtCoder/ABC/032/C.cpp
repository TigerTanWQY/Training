#include <bits/stdc++.h>
using namespace std;

int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	if(count(a + 1, a + n + 1, 0)) {
		cout << n << endl;
		return 0;
	} else if(*min_element(a + 1, a + n + 1) > k) {
		cout.put('0'); cout << endl;
		return 0;
	}
	int ans = 0;
	long long tot = 1;
	a[n + 1] = 0x3f3f3f3f;
	for(int i = 1, j = 1; j <= n + 1; ++j) {
		tot *= a[j];
		for(; tot > k; ++i)
			tot /= a[i];
		ans = max(ans, j - i + 1);
	}
	cout << ans << endl;
	return 0;
}
