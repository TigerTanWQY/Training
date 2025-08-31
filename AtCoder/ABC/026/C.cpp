#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 23;
vector<int> G[N];
int f[N];

int dfs(const int& u) {
	if(f[u])
		return f[u];
	int minn = 0x3f3f3f3f, maxn = 0;
	for(const auto& v: G[u]) {
		int x = dfs(v);
		minn = min(minn, x);
		maxn = max(maxn, x);
	}
	return f[u] = minn + maxn + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 2, fa; i <= n; ++i) {
		cin >> fa;
		G[fa].push_back(i);
	}
	for(int u = 1; u <= n; ++u)
		if(G[u].size() == 0)
			f[u] = 1;
	dfs(1);
	cout << f[1];
	return 0;
}