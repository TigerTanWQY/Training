#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e5 + 3;
vector<int> G[N];
bitset<N> vis;
int dep[N], cnt[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
//	memset(cnt, 0, sizeof(cnt));
	memset(dep, -1, sizeof(dep));
	dep[1] = 0;
	queue<int> q;
	q.push(1);
//	vis.reset();
	vis[1] = true;
	int ansd = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		cnt[u] = G[u].size() - (u != 1);
		for(const auto& v: G[u])
			if(!vis[v]) {
				vis[v] = true;
				dep[v] = dep[u] + 1;
				ansd = max(ansd, dep[v]);
				q.push(v);
			}
	}
	long long ansq = 0;
	for(int i = 1; i <= n; i++)
		if(dep[i] < ansd)
			ansq += k - (long long)cnt[i];
	cout << ansd << ' ' << ansq << endl;
	return 0;
}
