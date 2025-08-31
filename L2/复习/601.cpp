#include <iostream>
using namespace std;

long long s[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	for(int L, R; q--; cout.put('\n')) {
		cin >> L >> R;
		cout << s[R] - s[L - 1];
	}
	cout.flush();
	return 0;
}