#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, y, z;
	cin >> x >> y >> z;
	if(y < 0) {
		x = -x;
		y = -y;
		z = -z;
	}
	if(x < y)
		cout << abs(x);
	else if(z > y)
		cout << "-1";
	else
		cout << abs(z) + abs(x - z);
	return 0;
}
