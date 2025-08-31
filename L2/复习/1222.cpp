#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	cin >> a >> b;
	if(a == 1) {
		cout.put('1');
		cout << endl;
		return 0;
	}
	long long res = 1;
	for(; b; --b) {
		res *= a;
		if(res > 1e9) {
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << res << endl;
	return 0;
}