#include <iostream>
using namespace std;

long long r[13], b[13];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x, y;
	cin >> n >> x >> y;
	b[1] = 1;
	for(int i = 2; i <= n; ++i) {
		b[i] = r[i - 1] + b[i - 1] * y;
		r[i] = r[i - 1] + b[i] * x;
	}
	cout << r[n] << endl;
	return 0;
}