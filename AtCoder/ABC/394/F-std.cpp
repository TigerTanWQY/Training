#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<multiset<int>> maxc;
vector<int> dp;

void post_dfs(int u, int fa) {
	multiset<int> st;
	for(int v: adj[u]) {
		if(v == fa)
			continue;
		post_dfs(v, u);
		st.insert(max(1, dp[v]));
	}
	vector<int> tmp;
	for (auto it = st.crbegin(); it != st.crend() && tmp.size() < 4; ++it)
		tmp.push_back(*it);
	maxc[u] = multiset<int>(tmp.cbegin(), tmp.cend());
	if(tmp.size() >= 4)
		dp[u] = 1 + accumulate(tmp.cbegin(), tmp.cbegin() + 4, 0);
	else
		dp[u] = -1;
}

void pre_dfs(int u, int fa) {
	if(fa != -1) {
		multiset<int> st = maxc[fa];
		st.erase(st.find(max(1, dp[u])));
		vector<int> tmp1;
		for(auto it = st.crbegin(); it != st.crend() && tmp1.size() < 3; ++it)
			tmp1.push_back(*it);
		int val = 1;
		if(tmp1.size() >= 3)
			val += accumulate(tmp1.cbegin(), tmp1.cbegin() + 3, 0);
		else
			val = 1;
		maxc[u].insert(val);
		vector<int> tmp2;
		for(auto it = maxc[u].crbegin(); it != maxc[u].crend() && tmp2.size() < 4; ++it)
			tmp2.push_back(*it);
		maxc[u] = multiset<int>(tmp2.cbegin(), tmp2.cend());
		if(tmp2.size() >= 4)
			dp[u] = 1 + accumulate(tmp2.cbegin(), tmp2.cbegin() + 4, 0);
		else
			dp[u] = -1;
	}
	for(const auto& v: adj[u]) {
		if(v == fa)
			continue;
		pre_dfs(v, u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	adj.resize(n + 1);
	for(int i = 0, a, b; i < n - 1; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	maxc.resize(n + 1);
	dp.assign(n + 1, -1);
	post_dfs(1, -1);
	pre_dfs(1, -1);
	int ans = -1;
	for(int u = 1; u <= n; ++u)
		if(dp[u] != -1)
			ans = max(ans, dp[u]);
	cout << ans << endl;
	return 0;
}
