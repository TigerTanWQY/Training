#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x, y, z;
	cin >> x >> y >> z;
	if(x + y + z >= 22)
		cout << "bust";
	else
		cout << "win";
	cout.flush();
	return 0;
}