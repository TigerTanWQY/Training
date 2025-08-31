#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N];
int col[N], cnt1 = 0, cnt2 = 0;

void dfs(int u, int w) {
	if(col[u])
		return;
	else
	{ col[u] = 1; ++((w & 1)? cnt1: cnt2); }
	w = (w & 1) + 1;
	for(const auto& v: G[u])
		dfs(v, w);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= n; ++i)
		if(!col[i]) {
			cnt1 = cnt2 = 0;
			dfs(i, 1);
			if(cnt1 < cnt2)
			{ ans1 += cnt1; ans2 += cnt2; }
			else
			{ ans1 += cnt2; ans2 += cnt1; }
		}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}
