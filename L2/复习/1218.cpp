#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	unsigned n;
	cin >> n;
	if(n & 1) {
		cout << "-1" << endl;
		return 0;
	}
	for(int i = 24; i; --i)
		if(n >> i & 1)
			cout << (1 << i) << ' ';
	cout << endl;
	return 0;
}