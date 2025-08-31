#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 500'003;
vector<int> G[N];
int b[N], c[N], s[N][2];
LL a[N], ans;

void dfs(const int u, const int fa) {
	if(u != 1)
		a[u] = min(a[u], a[fa]);
	s[u][b[u]] += (b[u] != c[u]);
	for(const auto& v: G[u]) {
		if(v == fa)
			continue;
		dfs(v, u);
		s[u][0] += s[v][0];
		s[u][1] += s[v][1];
	}
	int t = min(s[u][0], s[u][1]);
	ans += a[u] * t * 2;
	s[u][0] -= t;
	s[u][1] -= t;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int tot1 = 0, tot2 = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
		tot1 += b[i];
		tot2 += c[i];
	}
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(tot1 != tot2) {
		cout << "-1";
		cout.flush();
		return 0;
	}
	dfs(1, 0);
	cout << ans;
	cout.flush();
	return 0;
}