#include <bits/stdc++.h>
using namespace std;

int c[103];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1, x; i <= m; ++i) {
		cin >> x;
		auto id = x? x: min_element(c + 1, c + n + 1) - c;
		++c[id];
		cout << id << ' ';
	}
	cout << endl;
	return 0;
}
