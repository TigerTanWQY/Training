#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 153;
vector<int> G[N];
int dout[N], f[N][N], m;

void dfs(const int u) {
	f[u][1] = dout[u];
	for(vector<int>::const_iterator it = G[u].begin(); it != G[u].end(); ++it) {
		int v = *it;
		dfs(v);
		for(int j = m; j; --j)
			for(int k = 1; k < j; ++k)
				f[u][j] = min(f[u][j], f[u][j - k] + f[v][k] - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n >> m;
	memset(f, 0x3f, sizeof(f));
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		++dout[u];
		G[u].push_back(v);
	}
	dfs(1);
	int ans = 0x3f3f3f3f;
	for(int u = 1; u <= n; ++u)
		if(u == 1)
			ans = min(ans, f[u][m]);
		else
			ans = min(ans, f[u][m] + 1);
	cout << ans;
	cout.flush();
	return 0;
}