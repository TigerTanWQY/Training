#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	if(n >= 200)
		n -= 50;
	if(n >= 100)
		n -= 20;
	cout << n;
	return 0;
}