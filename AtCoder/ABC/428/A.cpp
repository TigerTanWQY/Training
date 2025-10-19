#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int s, a, b, x;
	cin >> s >> a >> b >> x;
	cout << (x / (a + b) * a * s + min(x % (a + b), a) * s) << endl;
	return 0;
}
