#include <iostream>
#include <bitset>
#include <array>
using namespace std;
using LL = long long;

constexpr const int N = 19;
array<bitset<N>, N> a;
array<array<LL, N>, 1 << N> f;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int _ = 0, u, v; _ < m; ++_) {
		cin >> u >> v;
		--u; --v;
		a[u][v] = a[v][u] = true;
	}
	LL ans = 0;
	for(int i = 0; i < n; ++i)
		f[1 << i][i] = 1;
	for(int i = 1; i < 1 << n; ++i)
		for(int j = 0; j < n; ++j) {
			if(!f[i][j])
				continue;
			for(int k = 0; k < n; ++k)
				if(!a[j][k])
					continue;
				else if((i & -i) > 1 << k)
					continue;
				else if( 1 << k & i) {
					if(1 << k == (i & -i))
						ans += f[i][j];
				} else
					f[i | 1 << k][k] += f[i][j];
		}
	cout << (ans - m) / 2;
	cout.flush();
	return 0;
}