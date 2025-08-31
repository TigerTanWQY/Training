#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1, x, y; i <= m; ++i) {
		char col;
		cin >> x >> y >> col;
		a[i] = {x, y, col};
	}
	sort(a + 1, a + m + 1);
	int miny = 0x3f3f3f3f;
	for(int i = 1; i <= m; ++i) {
		const auto& [x, y, col] = a[i];
		if(col == 'W')
			miny = min(miny, y);
		else if(y >= miny) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
