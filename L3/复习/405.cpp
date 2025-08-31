#include <iostream>
#include <bitset>
using namespace std;

constexpr const int N = 8 + 3;
bitset<N> vis;
int G[N][N], n, ans = 0x3f3f3f3f;

void dfs(const int u, const int tot) {
	if(vis.count() == n) {
		ans = min(ans, tot + G[u][1]);
		return;
	}
	for(int v = 1; v <= n; ++v)
		if(!vis[v] && G[u][v]) {
			vis[v] = true;
			dfs(v, tot + G[u][v]);
			vis[v] = false;
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> G[i][j];
	vis[1] = true;
	dfs(1, 0);
	vis[1] = false;
	cout << ans << endl;
	return 0;
}