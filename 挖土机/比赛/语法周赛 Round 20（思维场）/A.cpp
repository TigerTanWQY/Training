#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int d = n / 4;
	if(d < 6) // 普通场
		cout << d + 1;
	else
		if(d & 1) // 简单场
			cout << (d - 5) / 2;
		else // 思维场
			cout << (d - 6) / 2 + 1;
	cout << endl;
	return 0;
}