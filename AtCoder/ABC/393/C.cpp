#include <bits/stdc++.h>
using namespace std;

unordered_set<int> G[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for(int u, v; m--; ) {
		cin >> u >> v;
		if(u == v)
			++ans;
		else if(G[u].count(v))
			++ans;
		else {
			G[u].insert(v);
			G[v].insert(u);
		}
	}
	cout << ans << endl;
	return 0;
}
