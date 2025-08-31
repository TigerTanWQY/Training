#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

LL s[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	for(int L; q--; cout.put('\n')) {
		LL x;
		cin >> L >> x;
		if(s[L] - s[L - 1] > x) {
			cout << "-1";
			continue;
		}
		int _L = 0, _R = n + 1;
		while(_L + 1 < _R) {
			int M = (_L + _R) >> 1;
			if(s[M] - s[L - 1] <= x)
				_L = M;
			else
				_R = M;
		}
		cout << _L;
	}
	cout.flush();
	return 0;
}