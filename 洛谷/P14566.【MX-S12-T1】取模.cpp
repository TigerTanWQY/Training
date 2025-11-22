#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		int mx1 = 0, mx2 = -1, mn = 1e9;
		for(int i = 1, x; i <= n; ++i) {
			cin >> x;
			if(x > mx1) {
				mx2 = mx1;
				mx1 = x;
			} else if(x != mx1 && x > mx2)
				mx2 = x;
			mn = min(mn, x);
		}
		cout << max(mx1 - mn, mx2);
	}
	cout.flush(); return 0;
}
