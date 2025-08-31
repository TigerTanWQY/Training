#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	int x = (a + 1) % 10, y = (a + 9) % 10;
	if(!x)
		x = 10;
	if(!y)
		y = 10;
	if(x == b || y == b)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}