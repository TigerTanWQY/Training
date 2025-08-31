#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	auto is_prime = [](int x) {
		if(x < 2)
			return false;
		for(int i = 2; i * i <= x; ++i)
			if(x % i == 0)
				return false;
		return true;
	};
	for(int x; n--; ) {
		cin >> x;
		if(is_prime(x))
			cout << x << ' ';
	}
	cout << endl;
	return 0;
}
