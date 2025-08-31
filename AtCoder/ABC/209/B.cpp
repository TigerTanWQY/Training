#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, W;
	cin >> n >> W;
	for(int i = 1, tot = 0, x; i <= n; ++i) {
		cin >> x;
		tot += x;
		if(!(i & 1))
			--tot;
		if(tot > W) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
