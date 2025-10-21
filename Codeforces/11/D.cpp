#include <bits/stdc++.h>
using namespace std;
using U = unsigned;

constexpr const U N = 19;
bool a[N][N];
long long f[1U<<N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	U n, m;
	cin >> n >> m;
	for(U _ = 0, u, v; _ < m; ++_) {
		cin >> u >> v;
		--u; --v;
		a[u][v] = a[v][u] = true;
	}
	long long ans = 0;
	for(U i = 0; i < n; ++i)
		f[1U << i][i] = 1;
	for(U i = 1; i < 1U << n; ++i)
		for(U j = 0; j < n; ++j)
			if(f[i][j])
				for(U k = 0; k < n; ++k)
					if(!a[j][k])
						continue;
					else if((i & ((~i)+1)) > 1U << k)
						continue;
					else if(1U << k & i) {
						if(1U << k == (i & -i))
							ans += f[i][j];
					} else
						f[i | 1U << k][k] += f[i][j];
	cout << (ans - m) / 2 << endl;
	return 0;
}
