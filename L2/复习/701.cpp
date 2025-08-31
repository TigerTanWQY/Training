#include <iostream>
#include <algorithm>
using namespace std;

int a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int x; q--; cout.put('\n')) {
		cin >> x;
		int R = n - (upper_bound(a + 1, a + n + 1, x) - a) + 1, E = (upper_bound(a + 1, a + n + 1, x) - lower_bound(a + 1, a + n + 1, x)), L = n - R - E;
		cout << L << ' ' << E << ' ' << R;
	}
	cout.flush();
	return 0;
}