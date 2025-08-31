#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	unordered_set<int> s;
	long long ans = (1LL + k) * k / 2;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		if(1 <= x && x <= k)
			s.insert(x);
	}
	for(const auto& x: s)
		ans -= x;
	cout << ans;
	return 0;
}