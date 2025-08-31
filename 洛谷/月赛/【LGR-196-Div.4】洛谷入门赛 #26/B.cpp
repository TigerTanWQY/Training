#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a1, b1, c1, a2, b2, c2;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	if(a1 != a2) {
		if(a1 > a2)
			cout << 'A';
		else
			cout << 'B';
	} else if(b1 != b2) {
		if(b1 > b2)
			cout << 'A';
		else
			cout << 'B';
	} else if(c1 != c2) {
		if(c1 < c2)
			cout << 'A';
		else
			cout << 'B';
	}
	cout.flush();
	return 0;
}