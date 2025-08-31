#include <iostream>
#include <vector>
using namespace std;
using LL = long long;

constexpr const int P = 1e9 + 7, N = 100'003;
vector<int> G[N];
LL f[N][3];

void dfs(const int u, const int fa) {
	f[u][0] = f[u][1] = 1;
	for(const auto& v: G[u])
		if(v != fa) {
			dfs(v, u);
			f[u][0] = f[u][0] * (f[v][0] + f[v][1]) % P;
			f[u][1] = f[u][1] * f[v][0] % P;
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	cout << (f[1][0] + f[1][1]) % P;
	cout.flush();
	return 0;
}