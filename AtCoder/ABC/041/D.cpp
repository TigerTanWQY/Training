#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1 << 16;
int son[N];
long long f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		--u; --v;
		son[u] |= 1 << v;
	}
	f[0] = 1;
	for(int s = 0; s < 1 << n; ++s)
		for(int i = 0; i < n; ++i)
			if((son[i] & s) == son[i] && !(s >> i & 1))
				f[s | 1 << i] += f[s];
	cout << f[(1 << n) - 1] << endl;
	return 0;
}
