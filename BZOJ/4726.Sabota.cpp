#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

constexpr const int eps = 1e-10;
constexpr const int N = 500'003;
vector<int> G[N];
int sz[N], k;
double f[N], ans = 0.0;

void dfs(const int& u) {
	sz[u] = 1;
	if(!G[u].empty()) {
		for(const auto& v: G[u]) {
			dfs(v);
			sz[u] += sz[v];
		}
		for(const auto& v: G[u])
			f[u] = max(f[u], min(f[v], sz[v] / (sz[u] - 1.0) + eps));
	} else
		f[u] = 1;
	if(sz[u] > k)
		ans = max(ans, f[u]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int n; cin >> n >> k; ) {
		for(int v = 2, u; v <= n; ++v) {
			cin >> u;
			G[u].push_back(v);
		}
		dfs(1);
		cout << fixed << setprecision(6) << ans << '\n';
	}
	cout.flush();
	return 0;
}