#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	for(int i = 2, y; i <= n; ++i) {
		cin >> y;
		if(y > x) {
			cout << i;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}