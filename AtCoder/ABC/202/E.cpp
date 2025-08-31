#include <iostream>
#include <vector>
using namespace std;

const int N = 200003;
vector<int> G[N];
int fa[N], d[N];

void dfs(const int& u) {
	for(const auto& v: G[u]) {
		d[v] = d[u] + 1;
		dfs(v);
	}
}

bool check(const int& u, const int& v) {
	if(u == v)
		return true;
	for(const auto& w: G[u])
		if(check(w, v))
			return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, _q;
	cin >> n;
	for(int u = 2; u <= n; ++u) {
		cin >> fa[u];
		G[fa[u]].push_back(u);
	}
	dfs(1);
	cin >> _q;
	for(int u, k; _q--; ) {
		cin >> u >> k;
		int ans = 0;
		for(int v = 1; v <= n; ++v)
			if(d[v] == k && check(u, v))
				++ans;
		cout << ans << '\n';
	}
	cout.flush();
	return 0;
}