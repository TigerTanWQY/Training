#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e4 + 3;
vector<int> G[N];
int f[N], dis1[N], dis2[N], ans;

void dfs(int u) {
	if(dis1[u])
		return;
	for(const auto& v: G[u]) {
		dfs(v);
		if(dis1[v] + 1 >= dis1[u])
		{ dis2[u] = dis1[u]; dis1[u] = dis1[v] + 1; }
		else if(dis1[v] + 1 > dis2[u])
			dis2[u] = dis1[v] + 1;
	}
	ans = max(ans, dis1[u] + dis2[u]);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 2; j <= n / i; ++j)
			f[i * j] += i;
	for(int i = 2; i <= n; ++i)
		if(f[i] < i)
			G[f[i]].push_back(i);
	for(int i = 1; i <= n; ++i)
		dfs(i);
	cout << ans << endl;
	return 0;
}
