#include <iostream>
#include <bitset>
#include <array>
using namespace std;

constexpr const int P = 1e9 + 7, N = 21;
array<bitset<N>, N> a;
array<long long, 1 << N> f;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0, x; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			cin >> x;
			a[i][j] = !!x;
		}
	f[0] = 1;
	for(int j = 0; j < (1 << n); ++j) {
		int cnt = __builtin_popcount(j);
		for(int i = 0; i < n; ++i)
			if(a[cnt][i] && (j & (1 << i)) == 0)
				f[j | (1 << i)] = (f[j | (1 << i)] + f[j]) % P;
	}
	cout << f[(1 << n) - 1];
	return 0;
}