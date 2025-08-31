#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	if(n & 1)
		cout << "Black";
	else
		cout << "White";
	return 0;
}