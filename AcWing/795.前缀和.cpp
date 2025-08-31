#include <iostream>
using namespace std;

int s[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	for(int L, R; m--; ) {
		cin >> L >> R;
		cout << s[R] - s[L - 1] << '\n';
	}
	return 0;
}