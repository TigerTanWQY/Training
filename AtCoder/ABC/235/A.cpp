#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x;
	cin >> x;
	cout << (x / 100 + x / 10 % 10 + x % 10) * 111;
	return 0;
}