#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	cout << fixed << setprecision(10) << 1LL * n * m / 2.0 << ' ';
	if(x * 2 == n && y * 2 == m)
		cout << "1\n";
	else
		cout << "0\n";
	return 0;
}