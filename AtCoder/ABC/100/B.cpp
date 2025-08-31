#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int d, n;
	cin >> d >> n;
	if(d == 0) {
		if(n < 100)
			cout << n;
		else
			cout << "101";
	} else if(d == 1) {
		if(n < 100)
			cout << n * 100;
		else
			cout << "10100";
	} else {
		if(n < 100)
			cout << n * 10000;
		else
			cout << "1010000";
	}
	cout << endl;
	return 0;
}