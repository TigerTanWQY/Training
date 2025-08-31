#include <bits/stdc++.h>
using namespace std;

int a[103], f[50003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int tot = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		tot += a[i];
	}
	for(int i = 1; i <= n; ++i)
		for(int j = tot >> 1; j >= a[i]; --j)
			f[j] = max(f[j], f[j - a[i]] + a[i]);
	cout << tot - f[tot >> 1] << endl;
	return 0;
}
