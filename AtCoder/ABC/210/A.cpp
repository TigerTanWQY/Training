#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, x, y;
	cin >> n >> a >> x >> y;
	a = min(a, n);
	cout << x * a + y * (n - a);
	return 0;
}