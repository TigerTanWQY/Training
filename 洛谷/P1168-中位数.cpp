#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		a.insert(lower_bound(cbegin(a), cend(a), x), x);
		if(i & 1)
			cout << a[i / 2] << '\n';
	}
	cout.flush(); return 0;
}
