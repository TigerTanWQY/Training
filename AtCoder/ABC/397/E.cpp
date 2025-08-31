#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> G[N];
int f[N], k;

void dfs(int u, int fa) {
	int maxn = 0, minn = 1e9, cnt = 0;
	for(const auto& v: G[u]) {
		if(v == fa)
			continue;
		dfs(v, u);
		if(f[v] != k) {
			++cnt;
			maxn = max(maxn, f[v]);
			minn = min(minn, f[v]);
		}
	}
	switch(cnt) {
		case 0:
			f[u] = 1;
			break;
		case 1:
			f[u] = maxn + 1;
			break;
		case 2:
			if(maxn + minn + 1 == k) {
				f[u] = k;
				break;
			}
		default:
			cout << "No" << endl;
			exit(0);
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n >> k;
	for(int _ = 1, u, v; _ < n * k; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	cout << (f[1] != k? "No": "Yes") << endl;
	return 0;
}
