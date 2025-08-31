#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 2; i * i <= n; ++i)
		if(n % i == 0) {
			cout << n / i;
			break;
		}
	cout << endl;
	return 0;
}