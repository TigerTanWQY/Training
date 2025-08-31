#include <bits/stdc++.h>
using namespace std;

int s[53];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 2, x; i <= n; ++i) {
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	for(int i = 1; i < n; ++i) {
		for(int j = i + 1; j <= n; ++j)
			cout << s[j] - s[i] << ' ';
		cout << '\n';
	}
	cout.flush(); return 0;
}
