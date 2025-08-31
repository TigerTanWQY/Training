#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int L, R; _T--; ) {
		cin >> L >> R;
//		for(int i = L, j = R; j >= L; --j) {
//			int k = log(j) / log(3);
//		}
		cout << (long long) (log(1LL * (L + R) * (R - L + 1) / 2) / log(3)) << '\n';
	}
	cout.flush();
	return 0;
}