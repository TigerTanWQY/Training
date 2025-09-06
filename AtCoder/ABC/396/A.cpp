#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, a1, a2;
	cin >> n >> a1 >> a2;
	for(int i = 3, x; i <= n; ++i) {
		cin >> x;
		if(a1 == a2 && a2 == x) {
			cout << "Yes" << endl;
			return 0;
		}
		a1 = a2; a2 = x;
	}
	cout << "No" << endl;
	return 0;
}
