#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	if(n <= 125)
		cout << '4';
	else if(n <= 211)
		cout << '6';
	else
		cout << '8';
	return 0;
}