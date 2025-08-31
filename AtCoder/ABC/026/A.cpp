#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a;
	cin >> a;
	if(a & 1) // odd
		cout << (a / 2) * (a / 2 + 1);
	else // even
		cout << (a / 2) * (a / 2);
	return 0;
}