#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int X, Y, n;
	cin >> X >> Y >> n;
	int ansX = -1, ansY = -1;
	for(int x = 1; x <= n; ++x)
		for(int y = 1; y <= n; ++y)
			if(x * Y >= X * y && (x * ansY < ansX * y || ansX == -1)) {
				ansX = x;
				ansY = y;
			}
	cout << ansX << ' ' << ansY << endl;
	return 0;
}