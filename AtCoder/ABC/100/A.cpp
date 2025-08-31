#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	cin >> a >> b;
	if(a <= 8 && b <= 8)
		cout << "Yay!";
	else
		cout << ":(";
	cout << endl;
	return 0;
}