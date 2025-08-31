#include <iostream>
#include <vector>
using namespace std;
using LL = long long;

vector<LL> p{2};

bool is_prime(const LL& x) {
	for(const auto& y: p)
		if(x % y == 0)
			return false;
		else if(y * y > x)
			return true;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("file.out", "w", stdout);
	for(LL i = 3; i <= 1e18; ++i)
		if(is_prime(i)) {
			p.push_back(i);
			cout << i << ',';
		}
	return 0;
}