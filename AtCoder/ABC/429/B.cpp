#include <bits/stdc++.h>
using namespace std;

int a[103];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	long long tot = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		tot += a[i];
	}
	for(int i = 1; i <= n; ++i)
		if(tot - a[i] == m) {
			cout << "Yes" << endl;
			return 0;
		}
	cout << "No" << endl;
	return 0;
}
