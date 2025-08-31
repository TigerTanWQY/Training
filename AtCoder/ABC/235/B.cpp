#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, last = 0;
	cin >> n;
	for(int i = 1, x; i <= n; last = x, ++i) {
		cin >> x;
		if(last >= x) {
			cout << last;
			return 0;
		}
	}
	cout << last;
	return 0;
}