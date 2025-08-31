#include <iostream>
using namespace std;

int phi(int x) {
	int res = x;
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0) {
			res /= i;
			res *= i - 1;
			for(; x % i == 0; x /= i);
		}
	if(x != 1) {
		res /= x;
		res *= x - 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int x; n--; ) {
		cin >> x;
		cout << phi(x) << '\n';
	}
	cout.flush();
	return 0;
}