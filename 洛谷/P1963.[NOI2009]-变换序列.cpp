#include<bits/stdc++.h>
using namespace std;

constexpr const int N = 1e4 + 3;
vector<int> G[N];
bitset<N> vis;
int lnkx[N], lnky[N], d[N];

bool dfs(int u) {
	if(vis[u])
		return false;
	vis[u] = true;
	for(const auto& v: G[u])
		if(lnky[v] == 0 || dfs(lnky[v])) {
			lnkx[u] = v; lnky[v] = u;
			return true;
		}
	return false;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> d[i];
	for(int i = 1; i <= n; ++i) {
		if(i + d[i] <= n)
			G[i].push_back(i + d[i]);
		if(i - d[i] >= 1)
			G[i].push_back(i - d[i]);
		if(i + n - d[i] <= n)
			G[i].push_back(i + n - d[i]);
		if(i - n + d[i] >= 1)
			G[i].push_back(i - n + d[i]);
		if(!G[i].empty())
			sort(begin(G[i]), end(G[i]));
	}
	int ans = 0;
	for(int i = n; i; --i) {
		ans += dfs(i);
		vis.reset();
	}
	if(ans < n)
		cout << "No Answer";
	else
		for(int i = 1; i <= n; ++i)
			cout << lnkx[i] - 1 << ' ';
	cout << endl;
	return 0;
}
