#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int x; _T--; cout.put('\n')) {
		cin >> x;
		cout << (x & 1? "zs wins": "pb wins");
	}
	cout.flush(); return 0;
}
