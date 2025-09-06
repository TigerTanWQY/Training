#include <bits/stdc++.h>
using namespace std;

int a[103];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	for(int x = n; x >= 0; --x) {
		int cnt = a + n - lower_bound(a, a + n, x);
		if (cnt >= x) {
			cout << x << endl;
			break;
		}
	}
	return 0;
}
