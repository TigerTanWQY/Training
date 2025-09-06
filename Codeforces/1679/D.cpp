#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
vector<int> G[N];
pair<int, int> e[N];
bitset<N> vis, ins;
int a[N], in[N], n, m;
LL dis[N], k;

bool chk(int tar) {
	vis.reset(); ins.reset();
	for(int i = 1; i <= n; ++i) {
		if(a[i] <= tar)
			ins[i] = true;
		G[i].clear();
		in[i] = dis[i] = 0;
	}
	for(int i = 1; i <= m; ++i) {
		auto [u, v] = e[i];
		if(a[u] <= tar && a[v] <= tar) {
			G[u].push_back(v);
			ins[u] = ins[v] = true;
			++in[v];
		}
	}
	queue<int> q;
	for(int i = 1; i <= n; ++i)
		if(!in[i] && ins[i]) {
			q.push(i);
			dis[i] = 1;
			vis[i] = true;
		}
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(const auto& v: G[u]) {
			dis[v] = max(dis[v], dis[u] + 1);
			if(!--in[v]) {
				vis[v] = true;
				q.push(v);
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		if(ins[i] && (!vis[i] || dis[i] >= k))
			return true;
	return false;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= m; ++i)
		cin >> e[i].first >> e[i].second;
	int L = 1, R = 1e9;
	while(L <= R) {
		int M = (L + R) >> 1;
		if(chk(M))
			R = M - 1;
		else
			L = M + 1;
	}
	cout << (L > 1e9? -1: L) << endl;
	return 0;
}
