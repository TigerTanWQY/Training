#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

constexpr const int N = 303;
vector<pair<int, int>> G[N];
bitset<N> vis;
int dep[N], f[N], dia[N], pre[N], suf[N], cnt, c;

void dfs(const int u, const int fa) {
	f[u] = fa;
	for(const auto& [v, w]: G[u]) {
		if(v == fa || vis[v])
			continue;
		dep[v] = dep[u] + w;
		if(dep[v] > dep[c])
			c = v;
		dfs(v, u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, s;
	cin >> n >> s;
	for (int i = 1, u, v, w; i < n; i++) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	dfs(1, 0);
	dep[c] = 0;
	dfs(c, 0);
	for(int u = c; u; u = f[u]) {
		dia[++cnt] = u;
		pre[cnt] = dep[u];
	}
	reverse(dia + 1, dia + cnt + 1);
	reverse(pre + 1, pre + cnt + 1);
	for(int i = cnt; i; i--)
		suf[i] = pre[cnt] - pre[i];
	for(int i = 1; i <= cnt; i++)
		vis[dia[i]] = true;
	int maxd = 0;
	for(int i = 1; i <= cnt; i++) {
		dep[dia[i]] = 0;
		c = 0;
		dfs(dia[i], 0);
		maxd = max(dep[c], maxd);
	}
	int L = 1, R = 1, ans = 0x3f3f3f3f;
	for(; L <= cnt; L++) {
		for(; R <= cnt && pre[R + 1] - pre[L] <= s; R++);
		ans = min(ans, max({maxd, pre[L], suf[R]}));
	}
	cout << ans;
	cout.flush();
	return 0;
}