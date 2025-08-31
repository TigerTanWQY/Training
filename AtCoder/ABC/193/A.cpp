#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	cout << fixed << setprecision(3) << (a - b) * 100.0 / a;
	return 0;
}