#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 3'003;
vector<pair<int, int>> G[N];
int a[N], f[N][N], n, m;

int dfs(const int u) {
	if(u > n - m) {
		f[u][1] = a[u];
		return 1;
	}
	int tot = 0;
	for(const auto& [v, w]: G[u]) {
		int res = dfs(v);
		tot += res;
		for(int j = tot; j; --j)
			for(int i = 1; i <= res; ++i)
				if(j - i >= 0)
					f[u][j] = max(f[u][j], f[u][j - i] + f[v][i] - w);
	}
	return tot;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int u = 1, k, v, w; u <= n - m; ++u) {
		cin >> k;
		while(k--) {
			cin >> v >> w;
			G[u].push_back({v, w});
		}
	}
	for(int i = n - m + 1; i <= n; ++i)
		cin >> a[i];
	memset(f,-0x3f,sizeof(f));
	for(int i = 1; i <= n; ++i)
		f[i][0] = 0;
	dfs(1);
	for(int i = m; i; --i)
        if(f[1][i] >= 0) {
			cout << i;
            break;
        }
	return 0;
}