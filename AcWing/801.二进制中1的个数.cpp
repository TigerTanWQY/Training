#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int x; n--; ) {
		cin >> x;
		cout << __builtin_popcount(x) << ' ';
	}
	return 0;
}