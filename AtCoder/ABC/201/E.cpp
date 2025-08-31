#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 1e9 + 7, N = 2e5 + 3;
vector<pair<int, LL>> G[N];
LL dis[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int _ = 1, u, v; _ < n; ++_) {
		LL w;
		cin >> u >> v >> w;
		--u; --v;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	memset(dis, -1, sizeof(dis));
	dis[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& [v, w]: G[u])
			if(!~dis[v]) {
				dis[v] = dis[u] ^ w;
				q.push(v);
			}
	}
	LL ans = 0;
	for(int i = 0; i < 60; ++i) {
		int cnt[2]{};
		for(int j = 0; j < n; ++j)
			++cnt[dis[j] >> i & 1];
		ans += (1LL << i) % P * cnt[0] % P * cnt[1] % P;
		ans %= P;
	}
	cout << ans << endl;
	return 0;
}
