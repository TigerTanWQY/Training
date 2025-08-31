#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 503;
vector<int> G[N];
int v[N], w[N], c[N];
long long f[N][50003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, V, k;
	cin >> n >> V >> k;
	for(int i = 1; i <= n; ++i)
		cin >> v[i] >> w[i] >> c[i];
	for(int i = 1; i <= n; ++i)
		G[c[i]].push_back(i);
	memset(f, -0x3f, sizeof(f));
	f[1][0] = 0;
	for(int i = 1; i <= n; ++i) {
		for(const auto& u: G[i])
			for(int j = V; j >= v[u]; --j)
				f[i + 1][j] = max({f[i + 1][j], f[i][j - v[u]] + w[u] + k, f[i + 1][j - v[u]] + w[u]});
		for(int j = 0; j <= V; ++j)
			f[i + 1][j] = max(f[i + 1][j], f[i][j]);
	}
	cout << *max_element(f[n + 1], f[n + 1] + V + 1) << endl;
	return 0;
}
