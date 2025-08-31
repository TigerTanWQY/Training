#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	for(int y; n--; ) {
		cin >> y;
		if(y != x)
			cout << y << ' ';
	}
	return 0;
}