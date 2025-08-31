#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e3 + 3;
bitset<N> f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		f[i][i] = true;
	for(int u, v; m--; ) {
		cin >> u >> v;
		f[u][v] = true;
	}
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			if(f[i][k])
				f[i] |= f[k];
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += f[i].count();
	cout << ans << endl;
	return 0;
}
