#include <iostream>
#include <string>
using namespace std;

bool is_prime(const int& x) {
	if(x < 2)
		return false;
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	for(int i = 10; i <= n; ++i)
		s += to_string(i);
	n = s.size();
	int ans = 0;
	for(int i = 0; i <= n - 4; ++i) {
		int x = stoi(s.substr(i, 4));
		if(1000 <= x && x < 10000 && is_prime(x))
			++ans;
	}
	cout << ans;
	return 0;
}