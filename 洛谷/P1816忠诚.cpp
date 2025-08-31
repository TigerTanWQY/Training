#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int f[20][100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> f[0][i];
		for(int j = 1; j <= 17; ++j)
			f[j][i] = 0x3f3f3f3f;
	}
	for(int j = 1; j <= 17; ++j)
		for(int i = 1; i <= n - (1 << j) + 1; ++i)
			f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << j - 1)]);
	for(int L, R; q--; ) {
		cin >> L >> R;
		int j = log2(R - L + 1);
		cout << min(f[j][L], f[j][R - (1 << j) + 1]) << ' ';
	}
	cout << endl;
	return 0;
}