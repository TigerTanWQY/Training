#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n, a, b, c; _T--; cout.put('\n')) {
		cin >> n >> a >> b >> c;
		const int m = a + b + c, r = n % m;
		cout << (n / m * 3 + !!r + (r > a) + (r > a + b));
	}
	cout.flush();
	return 0;
}
