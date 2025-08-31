#include <iostream>
using namespace std;

const int N = 3000003;
int inv[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, _p;
	cin >> n >> _p;
	const int P = _p;
	inv[1] = 1;
	cout << inv[1] << '\n';
	for(int i = 2; i <= n; ++i) {
		inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
		cout << inv[i] << '\n';
	}
	cout.flush();
	return 0;
}