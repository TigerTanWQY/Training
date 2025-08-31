#include <iostream>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int x, y, z, k, s; _T--; cout.put('\n')) {
		cin >> x >> y >> z >> k >> s;
		int L = 0, R = s + 1;
		while(L + 1 < R) {
			const int M = (L + R) >> 1;
			if(x + (LL)y * M - (LL)z * (s - M) <= k + y - 1)
				L = M;
			else
				R = M;
		}
		cout << x + (LL)y * L - (LL)z * (s - L);
	}
	return 0;
}