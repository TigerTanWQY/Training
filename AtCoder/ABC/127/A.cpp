#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	cin >> a >> b;
	if(a >= 13)
		cout << b;
	else if(a >= 6)
		cout << b / 2;
	else
		cout.put('0');
	cout.flush();
	return 0;
}