#include <bits/stdc++.h>
using namespace std;
using U = unsigned;

constexpr const U P = 1e9 + 7, N = 21;
bool a[N][N];
unsigned long long f[1<<N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	U n;
	cin >> n;
	for(U i = 0, x; i < n; ++i)
		for(U j = 0; j < n; ++j) {
			cin >> x;
			a[i][j] = x;
		}
	f[0] = 1;
	for(U j = 0; j < (1U << n); ++j) {
		U cnt = popcount(j);
		for(U i = 0; i < n; ++i)
			if(a[cnt][i] && !(j & (1U << i)))
				f[j | (1U << i)] = (f[j | (1U << i)] + f[j]) % P;
	}
	cout << f[(1U << n) - 1];
	return 0;
}
