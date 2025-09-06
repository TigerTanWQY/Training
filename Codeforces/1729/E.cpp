#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int i = 2; i <= 26; ++i) {
		cout << "? 1 " << i << endl;
		long long x, y;
		cin >> x;
		if(x == -1) {
			cout << "! " << i - 1 << endl;
			return 0;
		}
		cout << "? " << i << " 1" << endl;
		cin >> y;
		if(x != y) {
			cout << "! " << x + y << endl;
			return 0;
		}
	}
	return 0;
}
