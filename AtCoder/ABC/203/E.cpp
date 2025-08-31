#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> G;
unordered_set<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	ans.insert(n);
	for(const auto& [_, a]: G) {
		unordered_set<int> st;
		for(const auto &u: a)
			if(ans.count(u + 1) || ans.count(u - 1))
				st.insert(u);
		for(const auto &u: a)
			if(ans.count(u))
				ans.erase(u);
		ans.insert(st.cbegin(), st.cend());
	}
	cout << ans.size() << endl;
	return 0;
}
