#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, last;
	cin >> n >> last;
	for(int i = 1, x; i < n; ++i) {
		cin >> x;
		cout << x * last << ' ';
		last = x;
	}
	return 0;
}