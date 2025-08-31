#include <iostream>
#include <unordered_set>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	LL n;
	cin >> n;
	unordered_set<LL> s;
	for(LL a = 2; a * a <= n; ++a) {
		LL x = a * a;
		while(x <= n) {
			s.insert(x);
			x *= a;
		}
	}
	cout << n - s.size();
	return 0;
}