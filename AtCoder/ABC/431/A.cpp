#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	cout << max(0, a - b) << endl;
	return 0;
}
