#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int x, y; T--; ) {
		cin >> x >> y;
		int n = (y - x) / 2;
		if(n <= 12000)
			cout << '5';
		else if(n <= 18000)
			cout << '6';
		else if(n <= 24000)
			cout << '8';
		else if(n <= 36000)
			cout << "11";
		else
			cout << 13 * (n / 48000 + !!(n % 48000));
		cout << '\n';
	}
	return 0;
}