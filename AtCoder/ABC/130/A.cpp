#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	if(a < b)
		cout << "0\n";
	else
		cout << "10\n";
	return 0;
}