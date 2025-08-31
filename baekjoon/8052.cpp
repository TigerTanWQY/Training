#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

constexpr const int N = 253;
vector<int> G[N];
bitset<N> vis;
int e, ans = 0x3f3f3f3f;

void dfs(const int u, const int dis) {
	if(u == e) {
		if(dis & 1)
			ans = min(ans, dis);
		return;
	}
	vis[u] = true;
	for(const auto& v: G[u])
		if(!vis[v])
			dfs(v, dis + 1);
	vis[u] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, s;
	cin >> n >> m >> s >> e;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(s, 1);
	if(ans == 0x3f3f3f3f)
		cout << "NIE";
	else
		cout << ans;
	cout.flush();
	return 0;
}