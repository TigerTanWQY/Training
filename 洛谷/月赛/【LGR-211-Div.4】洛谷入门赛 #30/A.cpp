#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, c, d, x;
	cin >> a >> b >> c >> d >> x;
	cout << b * (x >= a) + d * (x >= c) << endl;
	return 0;
}
