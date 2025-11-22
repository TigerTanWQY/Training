#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		int mx = 0, mn = 1e9;
		for(int i = 1, x; i <= n; ++i) {
			cin >> x;
			mx = max(mx, x);
			mn = min(mn, x);
		}
		cout << mx - mn;
	}
	cout.flush(); return 0;
}
