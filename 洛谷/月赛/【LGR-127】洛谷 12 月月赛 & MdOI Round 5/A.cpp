#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; cout << '\n') {
		cin >> n;
		if(n & 1)
			cout << 32 - __builtin_clz(n);
		else
			cout << "-1";
	}
	cout.flush();
	return 0;
}