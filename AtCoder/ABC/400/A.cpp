#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int x;
	cin >> x;
	cout << (400 % x? -1: 400 / x) << endl;
	return 0;
}
