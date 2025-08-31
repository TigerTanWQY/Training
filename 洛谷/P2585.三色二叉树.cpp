#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 500'003;
char s[N];
int f[N][3], g[N][3], idx = 0, res = 1;

void dfs(const int u) {
	if(s[u] == '0') {
		f[u][0] = g[u][0] = 1;
		return;
	}
	dfs(++idx);
	if(s[u] == '1') {
		f[u][0] = max(f[u + 1][1], f[u + 1][2]) + 1;
		f[u][1] = max(f[u + 1][0], f[u + 1][2]);
		f[u][2] = max(f[u + 1][0], f[u + 1][1]);
		g[u][0] = min(g[u + 1][1], g[u + 1][2]) + 1;
		g[u][1] = min(g[u + 1][0], g[u + 1][2]);
		g[u][2] = min(g[u + 1][0], g[u + 1][1]);
	} else {
		int k = ++idx;
		dfs(k);
		f[u][0] = max(f[u + 1][1] + f[k][2], f[u + 1][2] + f[k][1]) + 1;
		f[u][1] = max(f[u + 1][0] + f[k][2], f[u + 1][2] + f[k][0]);
		f[u][2] = max(f[u + 1][0] + f[k][1], f[u + 1][1] + f[k][0]);
		g[u][0] = min(g[u + 1][1] + g[k][2], g[u + 1][2] + g[k][1]) + 1;
		g[u][1] = min(g[u + 1][0] + g[k][2], g[u + 1][2] + g[k][0]);
		g[u][2] = min(g[u + 1][0] + g[k][1], g[u + 1][1] + g[k][0]);
	}
	res = max(res, f[u][0]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> (s + 1);
	dfs(++idx);
	cout << res << ' ' << min({g[1][0], g[1][1], g[1][2]});
	cout.flush();
	return 0;
}