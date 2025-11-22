#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int x, y, z;
	cin >> x >> y >> z;
	for(int k = 0; k <= 1000; ++k)
		if((x+k) % (y+k) == 0 && (x+k) / (y+k) == z) {
			cout << "Yes" << endl;
			return 0;
		}
	cout << "No" << endl;
	return 0;
}
