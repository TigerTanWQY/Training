#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 998244353, N = 1e6 + 3;
vector<int> G[N];
int out[N];
LL f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int id, n, m;
	cin >> id >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		++out[u];
	}
	for(int u = 1; u <= n; ++u) {
		int g = out[u] + 1;
		for(const auto& v: G[u])
			g = (g + (f[u - 1] - f[v - 1] + P) % P) % P;
		f[u] = (f[u - 1] + g) % P;
	}
	cout << f[n] << endl;
	return 0;
}
